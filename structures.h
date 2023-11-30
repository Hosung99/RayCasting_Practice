#ifndef STRUCTURES_H
# define STRUCTURES_H


typedef struct s_vec3 t_vec3;
typedef struct t_point3 t_point3;
typedef struct t_color3 t_color3;
typedef	struct s_ray t_ray;
typedef struct s_camera t_camera;
typedef struct s_canvas t_canvas;

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
	double x;
	double y;
	double z;
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
};

#endif
