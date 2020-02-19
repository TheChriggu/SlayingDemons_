uniform sampler2D diffuseTex;

varying vec2 pxpos;

void main()
{

    float offset = 0.001f;
    float red = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(offset,0)).r;
    float green = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(0,offset)).g;
    float blue = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(offset,offset)).b;

    gl_FragColor = vec4(red, green, blue, clamp(red+green+blue,0,1));
}