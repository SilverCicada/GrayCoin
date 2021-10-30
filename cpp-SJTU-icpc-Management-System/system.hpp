#include "base.hpp"
#include "class.h"
#include <tuple>
#include <set>
#include <map>
#include <optional>
#include <functional>
#include <atomic>

#include <cassert>

class SystemCore
{
private:
    
    // variable table 
    std::set<TeamInfo> teams_;      // todo: perhaps hash faster
    std::set<ProblemInfo> pblms_;   
    std::vector<SubmitInfo> submits_;
    
    // competition info 
    size_t dura_;
    std::vector<TeamInfo> rank_;

    // competition state
    bool started_;
    bool frozen_;

private:
    SystemCore(const SystemCore&) = delete;

public:
    SystemCore() : teams_(), pblms_(), submits_(), dura_(0U), rank_(), started_(false), frozen_(false) {}
    std::set<TeamInfo>& teams() { return this->teams_; }
    std::set<ProblemInfo>& pblms() { return this->pblms_; }
    std::vector<SubmitInfo>& submits() { return this->submits_; }
    std::vector<TeamInfo>& rank() { return this->rank_; }

    void start_competition(size_t dura, size_t problem_count)
    {
        assert(started_ == false);    // check for test

        // blip 'start_' flag to true 
        started_ = !started_;

        // set 'dura_'
        dura_ = dura;

        // init problems table
        for (size_t i = 0; i < problem_count; i++)
        {
            auto newprob = Problem::new_problem(('A' + i));
            pblms_.insert(newprob);
        }

        // init current rank
        for (auto& team : teams_)
            this->rank_.push_back(team);
        
        // sort rank by dictionary 
        std::ranges::sort(rank_, [](const TeamInfo& front, const TeamInfo& back) { return front->name() < back->name(); });
    }

    
    std::optional<TeamInfo> get_team_by_name(const std::string& name)
    {
        auto ret = std::find_if(this->teams_.begin(), this->teams_.end(), 
            [&](const TeamInfo& info) { return info->name() == name; });
        return ret == this->teams_.end() ? std::nullopt : std::make_optional(*ret);
    }

    std::optional<ProblemInfo> get_problem_by_name(const char name)
    {
        auto ret = std::find_if(this->pblms_.begin(), this->pblms_.end(),
            [&](const ProblemInfo& info) { return info->name() == name; });
        return ret == this->pblms_.end() ? std::nullopt : std::make_optional(*ret);
    }
    
    bool has_started() { return this->started_; }

    bool in_frozen() { return this->frozen_; }

    void blip_freeze_flag() { frozen_ = !frozen_; }


};

// condition code + optional appendix 
using Result = std::tuple<int, std::optional<std::string>>;

// process each instruction
using Reactor = std::function<Result (/*mutable*/ SystemCore&, const Instruction::ParamPack&)>;

// instruction processor map 
using ProcMap = std::map<OpKind, Reactor>;

class SystemProxy
{
private:
    SystemCore core_;
    
    static ProcMap Map;
private:
    SystemProxy() = default;

public:

    Result react(const Command& cmd)
    {
        auto& functor = SystemProxy::Map.at(cmd->opcode().as_enum());
        return std::invoke(functor, this->core_, cmd->args());
    }

    std::string on_query_submit(SubmitInfo team)
    {
        // todo 

        return std::string();
    }

    std::string on_query_rank(size_t rank)
    {
        std::string str;

        // todo 

        return str;
    }

    static void init_map();

public:
    // singleton pattern 
    static SystemProxy* instance()
    {
        static SystemProxy proxy;
        static bool init_flag{false};
        if (not init_flag) {    
            
            // call once 
            SystemProxy::init_map();
            init_flag = true;
        }
       
        return &proxy;
    }

};