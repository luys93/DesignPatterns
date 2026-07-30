#pragma once

#include <memory>
#include <iostream>

class AudioManager
{
	private:
		std::string str{""};
		AudioManager() = default;
	
	public:
		~AudioManager() = default;
		AudioManager(const AudioManager& other) = delete;
		AudioManager& operator=(const AudioManager& other) = delete;
		AudioManager(AudioManager&&) noexcept = delete;
		AudioManager& operator=(AudioManager&&) noexcept = delete;
		void setString(const std::string& str);
		friend std::ostream& operator<<(std::ostream& os, const AudioManager& a);
		static AudioManager& getInstance();
};
