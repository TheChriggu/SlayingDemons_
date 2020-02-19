uniform sampler2D diffuseTex;
uniform sampler2D noiseTex;

uniform float time;
varying vec2 pxpos;

void main()
{
    float alpha = 0.0f;
    //curve from 0 to 0.5
    float stage = (sin(time) / 2) + 0.5;
    stage /= 5;

    float noisestrength = max(0, 6*texture2D(noiseTex, vec2(fract(stage*1.5), 0.5)).x - 4);

    float red = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(fract(stage),0)*noisestrength).r;
    alpha += texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(fract(stage),0)*noisestrength).a;

    float green = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(0,fract(stage))*noisestrength).g;
    alpha += texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(0,fract(stage))*noisestrength).a;

    float blue = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(fract(stage),fract(stage))*noisestrength).b;
    alpha += texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(fract(stage),fract(stage))*noisestrength).a;

    gl_FragColor = vec4(red, green, blue, clamp(alpha,0,1));
}