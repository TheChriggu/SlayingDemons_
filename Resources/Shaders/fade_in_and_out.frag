uniform sampler2D diffuseTex;
uniform float time;

varying vec2 pxpos;

void main()
{
    float brightness = sqrt(abs(sin(time*3.14159/5)));
    float alpha = (texture2D(diffuseTex, gl_TexCoord[0].xy)).a;
    vec4 color = vec4((texture2D(diffuseTex, gl_TexCoord[0].xy)*brightness*alpha).xyz,1);

    gl_FragColor = color;
}