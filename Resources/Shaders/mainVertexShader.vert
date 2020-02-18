varying vec2 pxpos;

void main()
{

	gl_Position = (gl_ModelViewProjectionMatrix * gl_Vertex);
	gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

	pxpos = gl_Position.xy;
}