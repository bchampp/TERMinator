#ifndef IMAGE_H_
#define IMAGE_H_

#pragma once
#include <cstdlib>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <gtkmm/image.h>

class Image : public Gtk::Image
{
public:
    Image(const std::string& file);
    void set_image(std::string& file);
    std::string to_text();
    ~Image();
private:
    std::string filepath;
	std::string equation;
	std::string language;
	bool DEBUG;
};

#endif
