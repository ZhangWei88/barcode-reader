/*
* Copyright 2022 Axel Waggershauser
*/
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <string>

namespace ZXing {

	class BitArray;

	namespace OneD {

		namespace DataBar {

			std::string DecodeExpandedBits(const BitArray& bits);

		} // DataBar

	} // namespace OneD

} // namespace ZXing
