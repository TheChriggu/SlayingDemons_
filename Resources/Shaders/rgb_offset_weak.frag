uniform sampler2D diffuseTex;

varying vec2 pxpos;

void main()
{

    float offset = 0.001f;
    float red = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(offset,0)).r;
    float green = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(0,offset)).g;
    float blue = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(offset,-offset)).b;
    float alpha = (red+green+blue)/3 + texture2D(diffuseTex, gl_TexCoord[0].xy).a;
    alpha = clamp(alpha,0,1);

    gl_FragColor = vec4(red, green, blue, alpha);
}