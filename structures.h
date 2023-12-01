#ifndef STRUCTURES_H
# define STRUCTURES_H

#define TRUE 1
#define FALSE 0
#define SP 1
#define PL 2
#define LIGHT_POINT 1
#define EPSILON 1e-6
#define LUMEN 2
#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_vec3 t_vec3;
typedef struct t_point3 t_point3;
typedef struct t_color3 t_color3;
typedef	struct s_ray t_ray;
typedef struct s_camera t_camera;
typedef struct s_canvas t_canvas;
typedef struct s_sphere t_sphere;
typedef struct s_hit_record t_hit_record;
typedef struct s_object t_object;
typedef struct s_light t_light;
typedef struct s_scene t_scene;
typedef struct s_plane t_plane;
struct s_canvas
{
	int width; //캔버스 높이
	int height; //캔버스 길이
	double aspect_ratio; //종횡비
};

struct s_vec3
{
	double x;
	double y;
	double z;
};

struct t_color3
{
	double r;
	double g;
	double b;
};

struct t_point3
{
	double x;
	double y;
	double z;
};

struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
};

struct s_camera
{
	t_point3 origin; //카메라 위치
	double	viewport_h; //뷰포트 높이
	double	viewport_w; //뷰포트 길이
	t_vec3	horizontal; //수평길이 벡터
	t_vec3	vertical; //수직길이 벡터
	double	focal_len; //초점거리
	t_point3 left_top; //왼쪽위 코너점
	double	fov; //수평시야범위
};

struct s_hit_record
{
	t_point3 point;
	t_vec3 normal; //교점의 법선벡터
	double t; //광선의 원점과 교점사이의 거리
	double tmin; //카메라 뒷부분. t < 0
	double tmax; //오브젝트가 카메라보다 너무 먼경우
	int	front_face;
	t_color3 albedo;
};

struct	s_object
{
	int				object_type;
	void			*element;
	void			*next;
	t_color3		albedo;
};

struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

struct  s_scene
{
	t_canvas	canvas;
	t_camera	camera;
	t_object	*world;
	t_object	*light;
	t_color3	ambient;
	t_ray		ray;
	t_hit_record	rec;
};

struct s_sphere
{
	t_point3 center;
	double	 radius1;
	double	 radius2;
};

struct s_plane
{
	t_vec3		dir; //평면의 방향벡터
	t_point3	point; //위치
	t_color3    color; //RGB
};

#endif
