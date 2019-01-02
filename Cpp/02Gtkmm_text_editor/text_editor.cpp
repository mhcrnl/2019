#include <gtkmm.h>
/* Compile: g++ 
 -------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "com.gmail.mhcrnl");
	
	Gtk::Window window;
	Gtk::Frame frame;
	Gtk::Grid grid;
	Gtk::Label lb_cels;
    Gtk::Entry en_cels;
    Gtk::Button bt_calc;
    
    Gtk::Label lb_fahr;
    
	window.set_default_size(500, 500);
	window.set_title("Text Editor");
	window.set_border_width(10);
	window.set_position(Gtk::WIN_POS_CENTER);

	window.add(frame);
	
	lb_cels.set_text("Celsius ");
    bt_calc.set_label("Calculeaza");
	
	frame.set_label("Convertor Cels to Fahr ");
	frame.set_label_align(Gtk::ALIGN_END, Gtk::ALIGN_START);
	frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);

	frame.add(grid);
	grid.add(lb_cels);
    grid.add(en_cels);
    grid.add(bt_calc);

	window.show_all_children(); 
	return app->run(window);
	
}
