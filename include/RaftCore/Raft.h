#ifndef RAFT_H_
#define RAFT_H_

#include "ApplyMsg.h"
#include "Config.h"
#include "Monsoon.h"
#include "Persister.h"
#include "RaftRpcUtil.h"
#include "Util.h"
#include <boost/any.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

/**
 * @brief 网络状态表示
 * @todo 可以在rpc中删除该字段，实际生产中是用不到的
 */
constexpr int Disconnected = 0; // 方便网络分区时debug，网络异常时为disconnected，只要网络正常就为AppNormal，防止matchIndex[]数组异常减小

constexpr int AppNormal = 1;

/**
 * @brief 投票状态
 */
constexpr int Killed = 0;
constexpr int Voted = 1;  // 本轮已投过票
constexpr int Expire = 2; // 投票（消息、竞选者）过期
constexpr int Normal = 3;

class Raft : public raftRpcProtoc::raftRpc
{
private:
    std::mutex m_mtx;
    std::vector<std::shared_ptr<RaftRpcUtil>> m_peers;
    std::shared_ptr<Persister> m_persister;
    int m_me;
    int m_mcurrentTerm;
    int m_votedFor;
    std::vector<raftRpcProtoc::LogEntry> m_logs;
};

#endif // !RAFT_H_