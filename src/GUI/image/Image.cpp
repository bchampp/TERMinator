#include <Image.h>

Image::Image(const std::string& file)
{
	filepath = file;
	DEBUG = true;
}

std::string Image::to_text()
{
    if(filepath=="")
    {
        return "Open an image to parse.";
    }
    // workaround for an issue with tesseract locales misbehaving
    char *old_ctype = strdup(setlocale(LC_ALL, NULL));
    setlocale(LC_ALL, "C");
    
	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
	// Initialize tesseract-ocr with English, without specifying tessdata path
	char* outText;
	if (api->Init(NULL, "eng"))
	{
		fprintf(stderr, "Could not initialize tesseract.\n");
		exit(1);
	}

	Pix *image = pixRead(filepath.c_str()); // Open image
	if (!image->data)
	{
		std::cout << "Could not open image" << std::endl;
	}
	api->SetImage(image);

	// Get OCR result
	outText = api->GetUTF8Text();
	if (DEBUG)
	{
		printf("The text in the image is:\n\n %s\n\n", outText);
	}

	std::string outString = outText;
	// Destroy used object and release memory
	api->End();
	delete[] outText;
	pixDestroy(&image);
    
    // restore your previous locale
    setlocale(LC_ALL, old_ctype);
    free(old_ctype);

	return std::string(outString);
}

void Image::set_image(std::string& file)
{
    filepath = file;
}

Image::~Image()
{
}

