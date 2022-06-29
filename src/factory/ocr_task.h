/************************************************
* Copyright MaybeShewill-CV. All Rights Reserved.
* Author: MaybeShewill-CV
* File: image_ocr_task.h
* Date: 22-6-8
************************************************/

#ifndef MM_AI_SERVER_OCR_TASK_H
#define MM_AI_SERVER_OCR_TASK_H

#include "factory/base_factory.h"
#include "factory/register_marco.h"
#include "models/base_model.h"
#include "models/ocr/db_text_detector.h"

namespace mortred {
namespace factory {

using mortred::factory::ModelFactory;
using mortred::models::BaseAiModel;

namespace ocr {
using mortred::models::ocr::DBTextDetector;

/***
 * create db text detector instance
 * @tparam INPUT
 * @tparam OUTPUT
 * @param detector_name
 * @return
 */
template<typename INPUT, typename OUTPUT>
static std::unique_ptr<BaseAiModel<INPUT, OUTPUT> > create_dbtext_detector(const std::string& detector_name) {
    REGISTER_AI_MODEL(DBTextDetector, detector_name, INPUT, OUTPUT)
    return ModelFactory<BaseAiModel<INPUT, OUTPUT> >::get_instance().get_model(detector_name);
}

}
}
}

#endif //MM_AI_SERVER_OCR_TASK_H
