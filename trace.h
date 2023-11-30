#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray     ray(t_point3 orig, t_vec3 dir);
t_point3    ray_at(t_ray *ray, double t);
t_ray	ray_primary(t_camera *camera, double u, double v); //가장 처음 카메라에서 출발한ray
t_color3	ray_color(t_ray *ray, t_sphere *sphere);
int		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
int		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
int		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);

#endif
