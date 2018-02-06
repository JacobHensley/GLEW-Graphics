#include "Font.h"

Font::Font(const String & filePath, float size)
	: m_FilePath(filePath), m_Size(size)
{
	m_FTAtlas = ftgl::texture_atlas_new(512, 512, 1);
	m_FTFont = ftgl::texture_font_new_from_file(m_FTAtlas, size, filePath.c_str());

	//Texture
}