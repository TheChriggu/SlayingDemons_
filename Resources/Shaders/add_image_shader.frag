uniform sampler2D diffuseTex;
uniform sampler2D blurTex;

varying vec2 pxpos;

void main()
{
    vec2 coords = gl_TexCoord[0].xy;
    vec4 sourceFragment = texture2D(diffuseTex, coords);
    coords.y = coords.y;
    vec4 bloomFragment = texture2D(blurTex, coords);
    gl_FragColor = sourceFragment + bloomFragment;
}