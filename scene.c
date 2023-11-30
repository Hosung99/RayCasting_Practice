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
	camera.viewport_h = 2.0;
	camera.viewport_w = 2.0 * canvas->aspect_ratio;
	camera.horizontal = vec3(camera.viewport_w, 0, 0);
	camera.vertical = vec3(0, camera.viewport_h, 0);
	camera.left_top.x = camera.origin.x - camera.viewport_w / 2;
	camera.left_top.y = camera.origin.y + camera.viewport_h / 2;
	camera.left_top.z = camera.origin.z - camera.focal_len;
	return (camera);
}
