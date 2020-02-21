uniform sampler2D diffuseTex;

varying vec2 pxpos;

void main()
{

    float offset = 0.001f;
    float alpha = 0.0f;

    float red = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(offset,0)).r;
    alpha += texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(offset,0)).a;

    float green = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(0,offset)).g;
    alpha += texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(0,offset)).a;

    float blue = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(offset,-offset)).b;
    alpha += texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(offset,-offset)).a;


    vec3 color = vec3(red,green,blue);

    gl_FragColor = vec4(color, alpha);
}