uniform sampler2D diffuseTex;
uniform vec2 sourceSize;

varying vec2 pxpos;

void main()
{
    vec2 pixelSize = vec2(1.0 / sourceSize.x, 1.0 / sourceSize.y);
    vec2 textureCoordinates = gl_TexCoord[0].xy;
    vec4 color = texture2D(diffuseTex, textureCoordinates);
    color     += texture2D(diffuseTex, textureCoordinates + vec2( 1.0,  0.0) * pixelSize);
    color     += texture2D(diffuseTex, textureCoordinates + vec2(-1.0,  0.0) * pixelSize);
    color     += texture2D(diffuseTex, textureCoordinates + vec2( 0.0,  1.0) * pixelSize);
    color     += texture2D(diffuseTex, textureCoordinates + vec2( 0.0, -1.0) * pixelSize);
    color     += texture2D(diffuseTex, textureCoordinates + vec2( 1.0,  1.0) * pixelSize);
    color     += texture2D(diffuseTex, textureCoordinates + vec2(-1.0, -1.0) * pixelSize);
    color     += texture2D(diffuseTex, textureCoordinates + vec2( 1.0, -1.0) * pixelSize);
    color     += texture2D(diffuseTex, textureCoordinates + vec2(-1.0,  1.0) * pixelSize);
    gl_FragColor = color / 9.0;
}