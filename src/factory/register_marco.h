/************************************************
* Copyright MaybeShewill-CV. All Rights Reserved.
* Author: MaybeShewill-CV
* File: model_register_marco.h
* Date: 22-6-8
************************************************/

#ifndef MM_AI_SERVER_REGISTER_MARCO_H
#define MM_AI_SERVER_REGISTER_MARCO_H

#include "factory/base_factory.h"
#include "models/model_io_define.h"

using mortred::models::BaseAiModel;
using mortred::server::BaseAiServer;
using mortred::factory::ModelRegistrar;
using mortred::factory::ServerRegistrar;

#define REGISTER_AI_MODEL(MODEL, MODEL_NAME, INPUT, OUTPUT) \
ModelRegistrar<BaseAiModel<INPUT, OUTPUT>, MODEL<INPUT, OUTPUT> > __model_registrar__##MODEL##_##INPUT##_##OUTPUT((MODEL_NAME));

#define REGISTER_AI_SERVER(SERVER, SERVER_NAME) \
ServerRegistrar<BaseAiServer, SERVER> __server_registrar__##SERVER((SERVER_NAME));

#endif //MM_AI_SERVER_REGISTER_MARCO_H
