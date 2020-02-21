uniform sampler2D diffuseTex;
uniform sampler2D noiseTex;

uniform float time;
varying vec2 pxpos;

void main()
{
	vec4 noiseCol = texture2D(noiseTex, vec2(0,gl_TexCoord[0].x))*0.1;
	noiseCol.x=0;
	float noisestrength = max(0, 6*texture2D(noiseTex, vec2(fract(time*1.5), 0.5)).x - 4);

	noisestrength *= 0;
	//noisestrength /= 2;

	float rowGlitch = max(0, 10*texture2D(noiseTex, vec2(fract(time*1.1+noiseCol.y), 0.8)).x - 8);
	rowGlitch *= step(fract(time*1.3+0.01+1.3*noiseCol.y), gl_TexCoord[0].y) * (1-step(fract(time*1.3+0.02+1.3*noiseCol.y), gl_TexCoord[0].y))
				+step(fract(time*1.4+0.04+1.2*noiseCol.y), gl_TexCoord[0].x) * (1-step(fract(time*1.4+0.05+1.2*noiseCol.y), gl_TexCoord[0].x));

	rowGlitch /= 10;


	float screenmultiplier = (fract(time));
	
	vec4 diffuseCol = texture2D(diffuseTex, gl_TexCoord[0].xy+noiseCol.yx*noisestrength);
	float red = texture2D(diffuseTex, gl_TexCoord[0].xy+noiseCol.yx*(rowGlitch) + vec2(fract(time),0)*noisestrength).r;
	float green = texture2D(diffuseTex, gl_TexCoord[0].xy+noiseCol.yx*(rowGlitch) + vec2(0,fract(time))*noisestrength).g;
	float blue = texture2D(diffuseTex, gl_TexCoord[0].xy+noiseCol.yx*(rowGlitch) + vec2(fract(time),fract(time))*noisestrength).b;

	gl_FragColor = vec4(red, green, blue, diffuseCol.a);
}