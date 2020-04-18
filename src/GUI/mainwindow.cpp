#include <mainwindow.h>
#include <Display.h>
#include "matplotlibcpp.h"
#include <opencv2/opencv.hpp>
#include <unistd.h>


#include <iostream>

namespace plt = matplotlibcpp;
using namespace std;
using namespace cv;

MainWindow::MainWindow(): input_box(Gtk::ORIENTATION_VERTICAL), output_box(Gtk::ORIENTATION_VERTICAL), input_button("Select Image"), test(),
output_label("Output"), output_solution("Solution to equation"), output_plot("Plot of equation"), input_image(string("")), output_image(string(""))
{
    // Sets the border width of the window.
    set_border_width(10);
    set_default_size(720, 480);
    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    input_button.signal_clicked().connect(sigc::mem_fun(*this,
              &MainWindow::on_button_clicked));

    evaluate_button.signal_clicked().connect(sigc::mem_fun(*this,
      &MainWindow::onEvaluateClicked));
    
    add(primary_box);
    primary_box.set_homogeneous();
    primary_box.pack_start(input_box, Gtk::PACK_EXPAND_WIDGET, 10);
    primary_box.pack_end(output_box, Gtk::PACK_EXPAND_WIDGET, 10);
    input_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    input_box.pack_start(input_frame, Gtk::PACK_EXPAND_WIDGET);
    input_frame.add(input_image);
    input_frame.add(test);
    input_frame.set_label("Input image");
    input_frame.set_label_align(0.5, 1.0);
    input_box.pack_start(input_button, Gtk::PACK_SHRINK, 0);
    input_button.set_hexpand(false);
    output_box.pack_start(output_label, Gtk::PACK_SHRINK);
    output_box.pack_start(output_notebook);
    output_frame.add(output_image);
    output_frame.set_label("Output Plot");
    output_frame.set_label_align(0.5, 1.0);
    // output_frame.add(output_image);
    output_equation.set_text(input_image.to_text());
    output_equation.set_line_wrap();
    output_equation.set_line_wrap_mode(Pango::WRAP_CHAR);
    output_notebook.append_page(output_equation, "Parsed Equation");
    output_notebook.append_page(output_solution, "Solution");
    output_notebook.append_page(output_frame, "Plot");
    // output_notebook.append_page(output_evaluate, "Evaluate");
    
    show_all_children();
}

MainWindow::~MainWindow(){}

void MainWindow::onEvaluateClicked(){

}

void MainWindow::on_button_clicked(){
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    //Add response buttons to the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    //Add filters, so that only certain file types can be selected:

    auto filter_image = Gtk::FileFilter::create();
    filter_image->set_name("Image files");
    filter_image->add_pixbuf_formats();
    dialog.add_filter(filter_image);

    //Show the dialog and wait for a user response:
    int result = dialog.run();

    //Handle the response:
    switch(result)
    {
        case(Gtk::RESPONSE_OK):
        {
            cout << "Open clicked." << endl;

            //Notice that this is a std::string, not a Glib::ustring.
            string filename = dialog.get_filename();
            set_input_image(filename);
            break;
        }
        case(Gtk::RESPONSE_CANCEL):
        {
            cout << "Cancel clicked." << endl;
            break;
        }
        default:
        {
            cout << "Unexpected button clicked." << endl;
            break;
        }
    }
    
}

void MainWindow::set_input_image(string filename){
    input_image.set_image(filename);
    input_buf = Gdk::Pixbuf::create_from_file(filename);
    // test.start();
    int height = input_buf->get_height();
    int width = input_buf->get_width();
    float ratio = static_cast<float>(input_image.get_allocated_width()-10)/width;
    // cout << ratio << "blah\n";
    Glib::RefPtr<Gdk::Pixbuf> temp_buf = input_buf->scale_simple(width*ratio, height*ratio, Gdk::INTERP_BILINEAR);
    // usleep(100000);
    // test.stop();
    input_image.set(temp_buf);
    output_equation.set_text(input_image.to_text());
    solve(input_image.to_text());
}

void MainWindow::solve(string equation){
    Equation eq(equation);
    eq.solve();
    output_solution.set_markup(generateOutputSolution(eq));
    plotSolution(equation);
}

std::string MainWindow::generateOutputSolution(Equation eq){
    std::string outputText = "<span size='x-large'>";

    return outputText;
}

void MainWindow::plotSolution(string eq){
    const string equation = eq;
    display test = display(equation);
}
