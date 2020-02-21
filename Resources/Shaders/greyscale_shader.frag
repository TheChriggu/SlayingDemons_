uniform sampler2D diffuseTex;

uniform float time;
varying vec2 pxpos;

void main()
{
    float threshhold = 0.2;
    float intensity = sin(time*5);
    intensity /= 2;
    intensity += 0.5;

    vec4 sourceFragment = texture2D(diffuseTex, gl_TexCoord[0].xy);
    float luminance = sourceFragment.r *0.3 + sourceFragment.g *0.59 + sourceFragment.b *0.11;
    sourceFragment *= clamp(luminance - threshhold, 0.0, 1.0) * 3.0*intensity;
    gl_FragColor = sourceFragment;
}