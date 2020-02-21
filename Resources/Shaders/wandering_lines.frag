uniform sampler2D diffuseTex;
uniform sampler2D noiseTex;

uniform float time;
varying vec2 pxpos;

void main()
{
    //curve from 0 to 1
    float stage = (sin(time) / 2) + 0.5;

    float noisestrength = max(0, 6*texture2D(noiseTex, vec2(gl_TexCoord[0].x, 0) + vec2(fract(stage*1.5), 0.5)).x - 4);

    float red = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(fract(stage),0)*noisestrength).r;
    float green = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(fract(stage),0)*noisestrength).g;
    float blue = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(fract(stage),0)*noisestrength).b;

    gl_FragColor = vec4(red, green, blue, clamp(red+green+blue,0,1));
}