uniform sampler2D texture;

void main()
{
    // lookup the pixel in the texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    // multiply it by the color
    //gl_FragColor = pixel;
    if (pixel == vec4(0,0,0,1))
    {
        pixel = vec4(0,0,0,0);
    }
    else
    {
        gl_FragColor = vec4(1.0 - pixel.r,1.0 -pixel.g,1.0 -pixel.b,1);
        //pixel = vec4(1.0 - pixel.r,1.0 -pixel.g,1.0 -pixel.b,1);
    }
}