#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H

#include <Image.h>
#include <Equation.h>
#include <gtkmm/application.h>
#include <gtkmm.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gdkmm/pixbuf.h>
#include <Display.h>


class MainWindow : public Gtk::Window
{

public:
  MainWindow();
  virtual ~MainWindow();

protected:
  // Button callbacks
  void on_button_clicked();
  void onEvaluateClicked();
  
  // Mutator Methods
  void set_input_image(const std::string filename);
  void set_input_text(const std::string filename);
  void set_plot_image(const std::string filename);

  // General Methods
  void solve(std::string equation);
  std::string generateOutputSolution(Equation eq);
  void plotSolution(string eq);
  void set_plot();

  //Member widgets:
  Gtk::Box primary_box, input_box, output_box;
  Gtk::Spinner test;
  Gtk::Button input_button, evaluate_button;
  Gtk::Frame input_frame, output_frame;
  Gtk::Notebook output_notebook;
  Gtk::Label output_label, output_equation, output_solution, output_plot, output_evaluate;
  Glib::RefPtr<Gdk::Pixbuf> input_buf, output_buf;
  Image input_image, output_image;

  
};

#endif // GTKMM_MAINWINDOW_H