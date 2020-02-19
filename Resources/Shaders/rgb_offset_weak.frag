uniform sampler2D diffuseTex;

uniform float time;
uniform float maxOffset;

varying vec2 pxpos;

void main()
{
    float sine = (sin(time) / 2) + 0.5;
    float offset = sine*maxOffset;
    vec4 diffuseCol = texture2D(diffuseTex, gl_TexCoord[0].xy);
    float red = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(offset,0)).r;
    float green = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(0,offset)).g;
    float blue = texture2D(diffuseTex, gl_TexCoord[0].xy + vec2(offset,offset)).b;

    gl_FragColor = vec4(red, green, blue, clamp(red+green+blue,0,1));
}