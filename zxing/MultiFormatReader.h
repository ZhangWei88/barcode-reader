/*
* Copyright 2016 Nu-book Inc.
* Copyright 2016 ZXing authors
*/
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "Result.h"

#include <vector>
#include <memory>

namespace ZXing {

	class Result;
	class Reader;
	class BinaryBitmap;
	class ReaderOptions;

	class MultiFormatReader
	{
	public:
		explicit MultiFormatReader(const ReaderOptions& opts);
		explicit MultiFormatReader(ReaderOptions&& opts) = delete;
		~MultiFormatReader();

		Result read(const BinaryBitmap& image) const;

		// WARNING: this API is experimental and may change/disappear
		Results readMultiple(const BinaryBitmap& image, int maxSymbols = 0xFF) const;

	private:
		std::vector<std::unique_ptr<Reader>> _readers;
		const ReaderOptions& _opts;
	};

} // ZXing
