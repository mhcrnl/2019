#!/usr/bin/gjs

imports.gi.versions.Gtk = '3.0';
const Gtk = imports.gi.Gtk;

class Boilerplate {

	constructor(){
		this.application = new Gtk.Application();

		this.application.connect('activate', this._onActivate.bind(this));
		this.application.connect('startup', this._onStartup.bind(this));
	}

	_onActivate(){
		this._window.present();
	}

	_onStartup() {
		this._buildUI ();
	}

	_buildUI() {
		this._window = new Gtk.ApplicationWindow({
			application: this.application,
			window_position: Gtk.WindowPosition.CENTER,
			border_width: 10,
			title: "Welcome to the Grid"});
		// Create a label
		this._label = new Gtk.Label({label: "Celsius: "});
		this._en_cels = new Gtk.Entry();
		this._bt_about = new Gtk.Button({label: "About"});

		this._lb_fahr = new Gtk.Label({label: "Fahrenheit"});
		this._en_fahr = new Gtk.Entry();
		this._bt_calc = new Gtk.Button({label: "Calculate"});
		this._bt_calc.connect("clicked", this._calc.bind(this));

		this._bt_close = new Gtk.Button({label: "Close"});
		this._bt_close.connect("clicked", Gtk.main_quit);
		// Create the grid
		this._grid = new Gtk.Grid();

		//Atach the label
		this._grid.attach(this._label, 0, 1, 1, 1);
		this._grid.attach_next_to(this._en_cels,this._label, Gtk.PositionType.RIGHT, 1, 1);
		this._grid.attach_next_to(this._bt_about, this._en_cels, Gtk.PositionType.RIGHT, 1, 1);
		this._grid.attach_next_to(this._lb_fahr, this._label, Gtk.PositionType.BOTTOM, 1, 1);
		this._grid.attach_next_to(this._en_fahr, this._lb_fahr, Gtk.PositionType.RIGHT, 1 ,1);
		this._grid.attach(this._bt_calc, 2, 2, 1, 1);
		this._grid.attach(this._bt_close, 2, 3, 3, 1);
		// Add the grid to the window
		this._window.add(this._grid);

		// Show the window and all child widgets
		this._window.show_all();

	}	
	_close_window() {
		_window.connect("delete-event", Gtk.main_quit);
		print("Hello");
	}

	_calc() {
		var cels = this._en_cels.get_text();
		var fahr = (cels * 9/5) + 32 ;
		//var str_fahr = String.valueOf(fahr); 
		this._en_fahr.set_text(`${fahr}`);
		print(cels);
	}
	
};

let app = new Boilerplate();
app.application.run (ARGV);

