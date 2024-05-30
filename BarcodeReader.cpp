// BarcodeReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "image_proc/stb_image.h"
#include "zxing/ReadBarcode.h"

int main(int argc, char** argv)
{
    if (argc < 1)
    {
        std::cout << "Image path argument required." << std::endl;
    }
    else
    {
        std::string filePath("F:\\barcode.png");
        int width, height, channels;
        const int forceChannels = 3;

        std::unique_ptr<stbi_uc, void (*)(void*)> buffer(stbi_load(filePath.c_str(), &width, &height, &channels, forceChannels),
            stbi_image_free);
        if (buffer == nullptr) {
            std::cerr << "Failed to read image: " << filePath << " (" << stbi_failure_reason() << ")" << "\n";
            return -1;
        }

        ZXing::ImageFormat format = ZXing::ImageFormat::None;
        if (channels == 1) {
            format = ZXing::ImageFormat::Lum;
        }
        else if (channels == 3) {
            format = ZXing::ImageFormat::RGB;
        }

        ZXing::ImageView image{ buffer.get(), width, height, format };
        auto options = ZXing::ReaderOptions().setFormats(ZXing::BarcodeFormat::Code128);
        auto barcodes = ZXing::ReadBarcodes(image, options);

        for (const auto& b : barcodes)
            std::cout << ZXing::ToString(b.format()) << ": " << b.text() << "\n";

        if (barcodes.size() == 0) {
            std::cout << "could not find any barcode." << std::endl;
        }
    }
    
    system("pause");
}