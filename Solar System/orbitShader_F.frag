uniform vec3 color;
uniform sampler2D img;

void main()
{
	gl_FragColor=vec4(color, 1.0);
}
