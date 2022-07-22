/************************************************
* Copyright MaybeShewill-CV. All Rights Reserved.
* Author: MaybeShewill-CV
* File: matting_task.h
* Date: 22-7-22
************************************************/

#ifndef MM_AI_SERVER_SCENE_SEGMENTATION_H
#define MM_AI_SERVER_SCENE_SEGMENTATION_H

#include "factory/base_factory.h"
#include "factory/register_marco.h"
#include "models/base_model.h"
#include "models/matting/modnet_matting.h"
#include "models/matting/pp_matting.h"

namespace jinq {
namespace factory {

using jinq::factory::ModelFactory;
using jinq::models::BaseAiModel;
using jinq::server::BaseAiServer;

namespace matting {
using jinq::models::matting::ModNetMatting;
using jinq::models::matting::PPMatting;

/***
 * create modnet human matting instance
 * @tparam INPUT
 * @tparam OUTPUT
 * @param detector_name
 * @return
 */
template<typename INPUT, typename OUTPUT>
static std::unique_ptr<BaseAiModel<INPUT, OUTPUT> > create_modnet_segmentor(const std::string& segmentor_name) {
    REGISTER_AI_MODEL(ModNetMatting, segmentor_name, INPUT, OUTPUT)
    return ModelFactory<BaseAiModel<INPUT, OUTPUT> >::get_instance().get_model(segmentor_name);
}

/***
 * create pp human matting instance
 * @tparam INPUT
 * @tparam OUTPUT
 * @param detector_name
 * @return
 */
template<typename INPUT, typename OUTPUT>
static std::unique_ptr<BaseAiModel<INPUT, OUTPUT> > create_ppmatting_segmentor(const std::string& segmentor_name) {
    REGISTER_AI_MODEL(PPMatting, segmentor_name, INPUT, OUTPUT)
    return ModelFactory<BaseAiModel<INPUT, OUTPUT> >::get_instance().get_model(segmentor_name);
}

}
}
}

#endif //MM_AI_SERVER_SCENE_SEGMENTATION_H
