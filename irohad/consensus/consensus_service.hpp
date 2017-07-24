/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IROHA_CONSENSUS_SERVICE_HPP
#define IROHA_CONSENSUS_SERVICE_HPP

#include <model/proposal.hpp>
#include <model/block.hpp>
#include <rxcpp/rx-observable.hpp>

namespace iroha {
  namespace consensus {
    /**
     * Consensus interface for peer communication service
     */
    class ConsensusService {
     public:

      /**
       * Vote for a block formed from proposal
       * @param block
       */
      virtual void vote_block(model::Block &block) = 0;

      /**
       * Return observable of all commits from the consensus
       * @return
       */
      virtual rxcpp::observable<rxcpp::observable<model::Block>> on_commit() = 0;
    };
  } // namespace consensus
} // namespace iroha

#endif //IROHA_CONSENSUS_SERVICE_HPP
