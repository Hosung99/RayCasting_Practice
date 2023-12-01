#include "scene.h"
# include "utils.h"

t_canvas canvas(int width, int height)
{
	t_canvas canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_camera camera(t_canvas *canvas, t_point3 origin)
{
	t_camera camera;

	camera.origin = origin;
	camera.focal_len = 1.0;
	camera.viewport_h = 4.0;
	camera.viewport_w = 4.0 * canvas->aspect_ratio;
	camera.horizontal = vec3(camera.viewport_w, 0, 0);
	camera.vertical = vec3(0, camera.viewport_h, 0);
	camera.left_top.x = camera.origin.x - camera.viewport_w / 2;
	camera.left_top.y = camera.origin.y - camera.viewport_h / 2;
	camera.left_top.z = camera.origin.z - camera.focal_len;
	camera.fov = 70;
	return (camera);
}


t_plane *plane(t_vec3 dir, t_point3 point, t_color3 color)
{
	t_plane *plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->point = point;
	plane->color = color;
	plane->dir = dir;
	return (plane);
}

t_sphere *sphere(t_point3 center, double radius)
{
	t_sphere *sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->radius1 = radius;
	sphere->radius2 = radius * radius;
	return (sphere);
}

t_object *object(int type, void *element, t_color3 albedo)
{
	t_object *new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->object_type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light *light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
