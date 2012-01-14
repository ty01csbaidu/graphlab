/**  
 * Copyright (c) 2009 Carnegie Mellon University. 
 *     All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an "AS
 *  IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 *  express or implied.  See the License for the specific language
 *  governing permissions and limitations under the License.
 *
 * For more about this software visit:
 *
 *      http://www.graphlab.ml.cmu.edu
 *
 */
 
/**
 * @file org_graphlab_Context.cpp
 * Implementations of native methods in \c org.graphlab.Context. Refer to
 * corresponding Javadoc.
 * @author Jiunn Haur Lim <jiunnhal@cmu.edu>
 */

#include "org_graphlab_Context.hpp"
#include "org_graphlab_Updater.hpp"

using namespace graphlab;

#ifdef __cplusplus
extern "C" {
#endif

  JNIEXPORT void JNICALL
  Java_org_graphlab_Context_schedule
  (JNIEnv *env, jobject obj,
  jlong context_ptr, jlong updater_ptr,
  jint vertex_id){
    
    if (NULL == env ||
        0 == context_ptr ||
        0 == updater_ptr){
      jni_core_type::throw_exception(
        env,
        "java/lang/IllegalArgumentException",
        "context_ptr and updater_ptr must not be null.");
        return;
    }

    // convert longs to pointers
    icontext_type *context = (icontext_type *) context_ptr;
    proxy_updater *proxy = (proxy_updater *) updater_ptr;
    
    context->schedule(vertex_id, *proxy);
    
  }

#ifdef __cplusplus
}
#endif