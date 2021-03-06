uniform sampler2D diffuseTex;
uniform sampler2D noiseTex;

uniform float time;
varying vec2 pxpos;

void main()
{
    float alpha = 0.0f;
    //curve from 0 to 1
    float stage = (sin(5*time) / 2) + 0.5;

    float noisestrength = max(0, 6*texture2D(noiseTex, vec2(gl_TexCoord[0].y, stage)).x - 4)*stage*0.01;

    float red = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(noisestrength*1.4, 0)).r;
    alpha = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(noisestrength*1.4, 0)).a;
    float green = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(noisestrength, 0)).g;
    alpha = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(noisestrength, 0)).a;
    float blue = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(noisestrength*0.7, 0)).b;
    alpha = texture2D(diffuseTex, gl_TexCoord[0].xy+ vec2(noisestrength*0.7, 0)).a;

    gl_FragColor = vec4(red, green, blue, clamp(alpha,0,1));
}