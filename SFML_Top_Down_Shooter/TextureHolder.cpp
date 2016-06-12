#include "TextureHolder.h"

#include <map>
#include <memory>
#include <SFML\Graphics.hpp>

namespace Textures
{
	enum ID { Landscape, Airplane, Missle };
}

TextureHolder::TextureHolder()
{

}

//Loads in textures and assigns them to an enum.
void TextureHolder::load(Textures::ID id, const std::string& filename)
{
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	texture->loadFromFile(filename);

	mTextureMap.insert(std::make_pair(id, std::move(texture)));
}
