/* main.c

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include "events.h"

GtkWidget *MAIN_WINDOW;
GtkWidget *MAIN_CONTAINER;
GtkWidget *CONTAINER_TOP_LEFT;
GtkWidget *CONTAINER_TOP_RIGHT;
GtkWidget *CONTAINER_BOTTOM_LEFT;
GtkWidget *CONTAINER_BOTTOM_RIGHT;
GtkWidget *SCROLL_WINDOW_TOP_LEFT;
GtkWidget *VIEWPORT_TOP_LEFT;
GtkWidget *GRID_TOP_LEFT;
GtkWidget *BUTTON_1;
GtkWidget *BUTTON_2;
GtkWidget *BUTTON_3;
GtkWidget *BUTTON_4;
GtkWidget *BUTTON_5;
GtkWidget *SPIN_BUTTON_1;
GtkWidget *SPIN_BUTTON_2;
GtkWidget *SCROLL_WINDOW_BOTTON_LEFT;
GtkWidget *SCROLL_WINDOW_BOTTON_RIGHT;
GtkWidget *VIEWPORT_BOTTOM_RIGHT;
GtkWidget *LIST_BOTTOM_RIGHT;
GtkWidget *TEXT_VIEW_BOTTOM_LEFT;
GtkWidget *TEXT_BUFFER_BOTTOM_LEFT;
GtkBuilder *BUILDER;

int main(int argc, char *argv[])
{

	gtk_init(&argc, &argv); // init Gtk

	//---------------------------------------------------------------------
	// establish contact with xml code used to adjust widget settings
	//---------------------------------------------------------------------

	BUILDER = gtk_builder_new_from_file("app-layout.glade");

	MAIN_WINDOW = GTK_WIDGET(gtk_builder_get_object(BUILDER, "main-window"));

	g_signal_connect(MAIN_WINDOW, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_builder_connect_signals(BUILDER, NULL);

	/* Getting widgets directly from the layout file w/ the builder */

	MAIN_CONTAINER =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "main-container"));
	CONTAINER_TOP_LEFT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "container-top-left"));
	CONTAINER_TOP_RIGHT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "container-top-right"));
	CONTAINER_BOTTOM_LEFT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "container-bottom-left"));
	CONTAINER_BOTTOM_RIGHT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "container-bottom-right"));

	SCROLL_WINDOW_TOP_LEFT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "scrolled-top-left"));
	VIEWPORT_TOP_LEFT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "view-top-left"));
	GRID_TOP_LEFT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "grid-top-left"));

	BUTTON_1 = GTK_WIDGET(gtk_builder_get_object(BUILDER, "button-1"));
	BUTTON_2 = GTK_WIDGET(gtk_builder_get_object(BUILDER, "button-2"));
	BUTTON_3 = GTK_WIDGET(gtk_builder_get_object(BUILDER, "button-3"));
	BUTTON_4 = GTK_WIDGET(gtk_builder_get_object(BUILDER, "button-4"));
	BUTTON_5 = GTK_WIDGET(gtk_builder_get_object(BUILDER, "button-5"));

	SPIN_BUTTON_1 = GTK_WIDGET(gtk_builder_get_object(BUILDER, "spin-button-1"));
	SPIN_BUTTON_2 = GTK_WIDGET(gtk_builder_get_object(BUILDER, "spin-button-2"));

	SCROLL_WINDOW_BOTTON_LEFT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "scrolled-bottom-left"));
	SCROLL_WINDOW_BOTTON_RIGHT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "scrolled-bottom-right"));
	VIEWPORT_BOTTOM_RIGHT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "view-bottom-right"));
	LIST_BOTTOM_RIGHT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "list-bottom-right"));
	TEXT_VIEW_BOTTOM_LEFT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "text-bottom-left"));
	TEXT_BUFFER_BOTTOM_LEFT =
			GTK_WIDGET(gtk_builder_get_object(BUILDER, "console-text-buffer"));

	gtk_widget_show(MAIN_WINDOW);

	// main loop
	gtk_main();

	return EXIT_SUCCESS;
}