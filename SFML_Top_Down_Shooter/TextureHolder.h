#pragma once


class TextureHolder
{

public:

	enum ID { Landscape, Airplane, Missle };

	TextureHolder();
	void load(ID id, const std::string& filename);

	sf::Texture& get(ID id);
	const sf::Texture& get(ID id) const;
	
private:
	std::map<ID, std::unique_ptr<sf::Texture>>mTextureMap;

	
};


