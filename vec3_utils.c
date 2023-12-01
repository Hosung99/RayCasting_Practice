#include "utils.h"

t_vec3      vec3(double x, double y, double z)
{
    t_vec3 vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    return (vec);
}

t_point3    point3(double x, double y, double z)
{
    t_point3 point;

    point.x = x;
    point.y = y;
    point.z = z;
    return (point);
}

t_color3    color3(double r, double g, double b)
{
    t_color3 color;

    color.r = r;
    color.g = g;
    color.b = b;
    return (color);
}

void        vset(t_vec3 *vec, double x, double y, double z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

double      vlength2(t_vec3 vec) //벡터 크기의 제곱
{
    return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double      vlength(t_vec3 vec)
{
    return (sqrt(vlength2(vec)));
}

t_vec3      plus_vec(t_vec3 vec, t_vec3 vec2)
{
    vec.x += vec2.x;
    vec.y += vec2.y;
    vec.z += vec2.z;
    return (vec);
}

t_point3      plus_point(t_point3 vec, t_point3 vec2)
{
    vec.x += vec2.x;
    vec.y += vec2.y;
    vec.z += vec2.z;
    return (vec);
}

t_color3      plus_color(t_color3 vec, t_color3 vec2)
{
    vec.r += vec2.r;
    vec.g += vec2.g;
    vec.b += vec2.b;
    return (vec);
}

t_vec3      vplus(t_vec3 vec, t_vec3 vec2)
{
    vec.x += vec2.x;
    vec.y += vec2.y;
    vec.z += vec2.z;
    return (vec);
}

t_vec3      vmult(t_vec3 vec, double t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;
    return (vec);
}

t_vec3      vmult_(t_vec3 vec, t_vec3 vec2)
{
    vec.x *= vec2.x;
    vec.y *= vec2.y;
    vec.z *= vec2.z;
    return (vec);
}

t_vec3      vplus_(t_vec3 vec, double x, double y, double z)
{
    vec.x += x;
    vec.y += y;
    vec.z += z;
    return (vec);
}

t_vec3      vminus(t_vec3 vec, t_vec3 vec2)
{
    vec.x -= vec2.x;
    vec.y -= vec2.y;
    vec.z -= vec2.z;
    return (vec);
}

t_vec3      vminus_(t_vec3 vec, double x, double y, double z)
{
    vec.x -= x;
    vec.y -= y;
    vec.z -= z;
    return (vec);
}

t_vec3      v_mult_vec(t_vec3 vec, double t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;
    return (vec);
}

t_point3 v_mult_point(t_point3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_color3 v_mult_color(t_color3 vec, double t)
{
	vec.r *= t;
	vec.g *= t;
	vec.b *= t;
	return (vec);
}


t_vec3      vdivide(t_vec3 vec, double t)
{
    vec.x *= 1 / t;
    vec.y *= 1 / t;
    vec.z *= 1 / t;

    return vec;
}

double      vdot(t_vec3 vec, t_vec3 vec2) //vec1 * vec2
{
    return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

t_vec3      vcross(t_vec3 vec, t_vec3 vec2)
{
    t_vec3 new;

    new.x = vec.y * vec2.z - vec.z * vec2.y;
    new.y = vec.z * vec2.x - vec.x * vec2.z;
    new.z = vec.x * vec2.y - vec.y * vec2.x;
    return (new);
}

t_vec3      vunit(t_vec3 vec)
{
    double len = vlength(vec);
    if (len == 0)
    {
        printf("Error\n:Devider is 0");
        exit(0);
    }
    vec.x /= len;
    vec.y /= len;
    vec.z /= len;
    return (vec);
}

t_color3 color_min(t_color3 color1,  t_color3 color2)
{
    if (color1.r > color2.r)
        color1.r = color2.r;
    if (color1.g > color2.g)
        color1.g = color2.g;
    if (color1.b > color2.b)
        color1.b = color2.b;
    return (color1);
}

t_vec3  vmin(t_vec3 vec1, t_vec3 vec2)
{
    if (vec1.x > vec2.x)
        vec1.x = vec2.x;
    if (vec1.y > vec2.y)
        vec1.y = vec2.y;
    if (vec1.z > vec2.z)
        vec1.z = vec2.z;
    return (vec1);
}
