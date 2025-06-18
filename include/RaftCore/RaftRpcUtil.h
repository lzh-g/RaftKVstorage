#ifndef RAFTRPC_H_
#define RAFTRPC_H_

#include <RaftRpcPro/protobuf/raftRPC.pb.h>

/**
 * @brief 维护当前节点对其他某个节点的所有rpc发送通信的功能
 * 对于一个raft节点来说，对于任意其他的节点都要维护一个rpc连接，即MprpcChannel
 */
class RaftRpcUtil
{
public:
    // 主动调用其他节点的三个方法，可以按照mit6824来调用，但是别的节点调用自己的好像不行，要继承protoc提供的service类才行
    bool AppendEntries(raftRpcProtoc::AppendEntriesArgs *args, raftRpcProtoc::AppendEntriesReply *response);
    bool InstallSnapShot(raftRpcProtoc::InstallSnapShotRequest *args, raftRpcProtoc::InstallSnapShotResponse *response);
    bool RequestVote(raftRpcProtoc::RequestVoteArgs *args, raftRpcProtoc::RequestVoteReply *response);

    /**
     * 响应其他节点的方法
     * @param ip 远端ip
     * @param port 远端端口
     */
    RaftRpcUtil(std::string ip, short port);
    ~RaftRpcUtil();

private:
    raftRpcProtoc::raftRpc_Stub *stub_;
};
#endif // !RAFTRPC_H_