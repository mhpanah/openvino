// Copyright (C) 2018-2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/core/node.hpp"
#include "openvino/pass/pattern/op/pattern.hpp"

namespace ov::pass {
namespace pattern::op {
/// A submatch on the graph value is performed on each input to the Or; the match
/// succeeds on the first match. Otherwise the match fails.
class OPENVINO_API Or : public Pattern {
public:
    OPENVINO_RTTI("patternOr");
    /// \brief creates an Or node matching one of several sub-patterns in order. Does
    /// not add node to match list.
    /// \param patterns The patterns to try for matching
    Or(const OutputVector& patterns) : Pattern(patterns) {}

    bool match_value(pattern::Matcher* matcher,
                     const Output<Node>& pattern_value,
                     const Output<Node>& graph_value) override;
};
}  // namespace pattern::op
OPENVINO_API std::shared_ptr<Node> operator|(const Output<Node>& lhs, const Output<Node>& rhs);
OPENVINO_API std::shared_ptr<Node> operator|(const std::shared_ptr<Node>& lhs, const std::shared_ptr<Node>& rhs);
}  // namespace ov::pass