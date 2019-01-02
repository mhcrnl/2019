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
	}
}

let app = new Boilerplate();
app.application.run (ARGV);

