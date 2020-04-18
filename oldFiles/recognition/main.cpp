#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> samples;

    samples.push_back("Sample1.png");
    samples.push_back("Sample2.png");
    samples.push_back("Sample3.jpg");
    samples.push_back("Sample4.jpg");
    samples.push_back("Sample5.png");
    samples.push_back("Sample6.png");
    samples.push_back("Sample7.jpg");
    int count = 0;
    for (auto sample : samples)
    {
        char *outText;
        count++;

        tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
        // Initialize tesseract-ocr with English, without specifying tessdata path
        if (api->Init(NULL, "eng"))
        {
            fprintf(stderr, "Could not initialize tesseract.\n");
            exit(1);
        }

        // Open input image with leptonica library

        Pix *image = pixRead(sample.c_str());
        api->SetImage(image);
        // Get OCR result
        outText = api->GetUTF8Text();

        printf("Sample # %d\n\n", count);
        printf("The text in the image is:\n\n %s\n\n", outText);

        // Destroy used object and release memory
        api->End();
        delete[] outText;
        pixDestroy(&image);
    }
    return 0;
}