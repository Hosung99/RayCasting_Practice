#ifndef SCENE_H
# define SCENE_H

# include "structures.h"

t_canvas    canvas(int  width, int height);
t_camera    camera(t_canvas *canvas, t_point3 origin);
t_sphere 	*sphere(t_point3 center, double radius);
t_plane *plane(t_vec3 dir, t_point3 point, t_color3 color);
t_object *object(int type, void *element, t_color3 albedo);
t_light	*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);

#endif
