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
		this._label = new Gtk.Label({label: "Welcome to GNOME!"});

		// Create the grid
		this._grid = new Gtk.Grid();

		//Atach the label
		this._grid.attach(this._label, 0, 1, 1, 1);

		// Add the grid to the window
		this._window.add(this._grid);

		// Show the window and all child widgets
		this._window.show_all();
	}
}

let app = new Boilerplate();
app.application.run (ARGV);

