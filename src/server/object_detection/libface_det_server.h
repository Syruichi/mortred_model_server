/************************************************
* Copyright MaybeShewill-CV. All Rights Reserved.
* Author: MaybeShewill-CV
* File: libface_det_server.h
* Date: 22-6-26
************************************************/

#ifndef MM_AI_SERVER_LIBFACEDETSERVER_H
#define MM_AI_SERVER_LIBFACEDETSERVER_H

#include <memory>

#include "server/abstract_server.h"

namespace jinq {
namespace server {
namespace object_detection {
class LibfaceDetServer : public jinq::server::BaseAiServer {
public:

    /***
    * constructor
    * @param config
    */
    LibfaceDetServer();

    /***
     *
     */
    ~LibfaceDetServer() override;

    /***
    * constructor
    * @param transformer
    */
    LibfaceDetServer(const LibfaceDetServer& transformer) = delete;

    /***
     * constructor
     * @param transformer
     * @return
     */
    LibfaceDetServer& operator=(const LibfaceDetServer& transformer) = delete;

    /***
     *
     * @param toml
     * @return
     */
    jinq::common::StatusCode init(const decltype(toml::parse(""))& cfg) override;

    /***
     *
     * @param task
     */
    void serve_process(WFHttpTask* task) override;

    /***
     *
     * @return
     */
    bool is_successfully_initialized() const override;

private:
    class Impl;
    std::unique_ptr<Impl> _m_impl;
};
}
}
}

#endif //MM_AI_SERVER_LIBFACEDETSERVER_H
