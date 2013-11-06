#pragma once

#include "core/plugins/interfaces/IMediaFile.h"
#include "core/details/TrackInfo.h"
#include "core/util/DAR.h"
#include "core/util/Resolution.h"
#include "core/details/CodecManager.h"
#include "packages/tools/chaptercreator/ChapterCreator.h"
#include "core/util/Util.h"
#include "packages/demuxer/mkvextract/MkvInfo.h"
#include "packages/tools/hdbdextractor/Eac3ToInfo.h"
#include "core/util/LogItem.h"
#include "core/util/VideoUtil.h"
#include "core/plugins/interfaces/ISettingsProvider.h"
#include "packages/tools/fileindexer/MeGUI.FileIndexerWindow.h"
#include "packages/audio/AudioCodecSettings.h"
#include "core/details/AudioTrackInfo.h"
#include "core/details/SubtitleTrackInfo.h"
#include "core/details/VideoTrackInfo.h"
#include "core/gui/MeGUI.MainForm.h"
#include "core/util/IFOparser.h"
#include "packages/tools/hdbdextractor/eac3to/StreamType.h"
#include "core/util/AudioUtil.h"
#include "core/util/GenericRegisterer.h"
#include "packages/reader/avs/AvsReader.h"
#include "packages/tools/avscreator/AviSynthWindow.h"
#include "packages/tools/avscreator/ScriptServer.h"
#include "core/gui/FPSChooser.h"
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include "stringconverter.h"

// ****************************************************************************
// 
// Copyright (C) 2005-2013 Doom9 & al
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
// 
// ****************************************************************************

//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Collections::Generic;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Globalization;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::IO;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Text;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Text::RegularExpressions;

using namespace MediaInfoWrapper;

using namespace MeGUI::core::details;
using namespace MeGUI::core::util;
using namespace MeGUI::packages::tools::hdbdextractor;

namespace MeGUI
{
	class MediaInfoException : public std::exception
	{
	public:
		MediaInfoException(std::exception &e);
	};

	class MediaInfoFileFactory : public IMediaFileFactory
	{

	public:
		IMediaFile *Open(const std::string &file);




		int HandleLevel(const std::string &file);



		const std::string &getID() const;

	};

	class MediaInfoFile : public IMediaFile
	{
	public:
		static MediaFile *Open(const std::string &file);

	private:
		static Regex *chaptersRegex;
		static Chapters *parseChapters(MediaInfoWrapper::ChaptersTrack *t);

		static SubtitleCodec *getSubtitleCodec(const std::string &p);

    public:
//C# TO C++ CONVERTER TODO TASK: There is no native C++ template equivalent to generic constraints:
		template<typename T> where T : class
		static Nullable<T> easyParse(Getter<T> parse);

	private:
		static CultureInfo *const culture;
		static std::map<std::string, VideoCodec*> knownVideoDescriptions;
		static std::map<std::string, AudioCodec*> knownAudioDescriptions;
		static std::map<std::string, ContainerType*> knownContainerTypes;
		static std::map<std::string, ContainerType*> knownContainerDescriptions;
		IMediaFile *videoSourceFile;
		IVideoReader *videoReader;
		ContainerType *cType;
		std::string _strContainer;
		std::string _file;
		VideoInformation *_VideoInfo;
		AudioInformation *_AudioInfo;
		SubtitleInformation *_SubtitleInfo;
		MkvInfo *_MkvInfo;
		Eac3toInfo *_Eac3toInfo;
		LogItem *_Log;
	public:
		const AudioInformation &getAudioInfo() const;

		const SubtitleInformation &getSubtitleInfo() const;

		const VideoInformation &getVideoInfo() const;

		const ContainerType &getContainerFileType() const;

		const std::string &getContainerFileTypeString() const;

//C# TO C++ CONVERTER TODO TASK: Calls to same-class constructors are not supported in C++ prior to C++0x:
//ORIGINAL LINE: public MediaInfoFile(string file, ref LogItem oLog) : this(file, ref oLog, 1)
		MediaInfoFile(const std::string &file, LogItem *&oLog);

		MediaInfoFile(const std::string &file, LogItem *&oLog, int iPGCNumber);

//C# TO C++ CONVERTER TODO TASK: Calls to same-class constructors are not supported in C++ prior to C++0x:
//ORIGINAL LINE: public MediaInfoFile(string file) : this(file, 1)
		MediaInfoFile(const std::string &file);

		MediaInfoFile(const std::string &file, int iPGCNumber);

		/// <summary>
		/// gets information about a source using MediaInfo
		/// </summary>
		/// <param name="file">the file to be analyzed</param>
		/// <param name="oLog">the log item</param>
	private:
		void GetSourceInformation(const std::string &file, LogItem *oLog, int iPGCNumber);

		void WriteSourceInformation(MediaInfo *oInfo, const std::string &strFile, LogItem *infoLog);

		void CorrectSourceInformation(MediaInfo *&oInfo, const std::string &strFile, LogItem *infoLog, int iPGCNumber);

		/// <summary>checks if the file is a MKV file and has chapters</summary>
		/// <returns>true if MKV has chapters, false if not</returns>
	public:
		bool hasMKVChapters();

		/// <summary>checks if the input file can be muxed to MKV</summary>
		/// <returns>true if MKV can be created</returns>
		bool MuxableToMKV();

		/// <summary>checks if the file is an eac3to demuxable file and has chapters</summary>
		/// <returns>track number or -1 if no chapters available</returns>
		int getEac3toChaptersTrack();

		/// <summary>extracts the MKV chapters</summary>
		/// <returns>true if chapters have been extracted, false if not</returns>
		bool extractMKVChapters(const std::string &strChapterFile);

		/// <summary>checks if the file is indexable by DGIndexNV</summary>
		/// <returns>true if indexable, false if not</returns>
		bool isDGIIndexable();

		/// <summary>checks if the file is indexable by DGIndex</summary>
		/// <returns>true if indexable, false if not</returns>
		bool isD2VIndexable();

		/// <summary>checks if the file is indexable by DGIndex</summary>
		/// <returns>true if indexable, false if not</returns>
		bool isDGAIndexable();

		/// <summary>checks if the file is indexable by FFMSindex</summary>
		/// <returns>true if indexable, false if not</returns>
		bool isFFMSIndexable();

		/// <summary>checks if the file is indexable by FFMSindex</summary>
		/// <returns>true if indexable, false if not</returns>
		bool isAVISourceIndexable(bool bStrictFilesOnly);

		/// <summary>gets the recommended indexer</summary>
		/// <param name="oType">the recommended indexer</param>
		/// <returns>true if a indexer can be recommended, false if no indexer is available</returns>
		bool recommendIndexer(FileIndexerWindow::IndexType &oType);

		/// <summary>gets the recommended indexer based on the priority</summary>
		/// <param name="oType">the recommended indexer</param>
		/// <param name="arrIndexer">the indexer priority</param>
		/// <returns>true if a indexer can be recommended, false if no indexer is available</returns>
		bool recommendIndexer(std::vector<std::string> &arrIndexer);

	private:
		FileIndexerWindow::IndexType _indexerToUse;
		/// <summary>gets the recommended indexer</summary>
	public:
		const FileIndexerWindow::IndexType &getIndexerToUse() const;
		void setIndexerToUse(const FileIndexerWindow::IndexType &value);

		/// <summary>checks if the file can be demuxed with eac3to</summary>
		/// <returns>true if demuxable, false if not</returns>
		bool isEac3toDemuxable();

	private:
		static Nullable<int> easyParseInt(const std::string &value);

		static Nullable<double> easyParseDouble(const std::string &value);

		static Nullable<decimal> easyParseDecimal(const std::string &value);

		static ContainerType *getContainerType(const std::string &codec, const std::string &description);

		static AudioCodec *getAudioCodec(const std::string &description);

		static VideoCodec *getVideoCodec(const std::string &description);

		static VideoType *getVideoType(VideoCodec *codec, ContainerType *cft, const std::string &filename);

		static AudioType *getAudioType(AudioCodec *codec, ContainerType *cft, const std::string &filename);
//C# TO C++ CONVERTER TODO TASK: Static constructors are not allowed in native C++:
		static MediaInfoFile();


	public:
		const bool &getHasAudio() const;

		const bool &getHasVideo() const;

		const bool &getCanReadVideo() const;

		const bool &getCanReadAudio() const;

		IVideoReader *GetVideoReader();

		IAudioReader *GetAudioReader(int track);

		const std::string &getFileName() const;



		~MediaInfoFile();


	private:
		void InitializeInstanceFields();
	};

	class VideoInformation
	{
	public:
		bool HasVideo;
		unsigned long long Width;
		unsigned long long Height;
		Dar DAR;
		unsigned long long FrameCount;
		double FPS;
		int FPS_N; // online needed for AVS file check
		int FPS_D; // online needed for AVS file check
		int PGCNumber;
		int PGCCount;

	private:
		std::string _strVideoScanType;
		VideoCodec *_vCodec;
		VideoType *_vType;
		VideoTrackInfo *_videoInfo;

	public:
		VideoInformation(bool hasVideo, unsigned long long width, unsigned long long height, Dar dar, unsigned long long frameCount, double fps, int fps_n, int fps_d);

		const VideoTrackInfo &getTrack() const;
		void setTrack(const VideoTrackInfo &value);

		const std::string &getScanType() const;
		void setScanType(const std::string &value);

		const VideoType &getType() const;
		void setType(const VideoType &value);

		const VideoCodec &getCodec() const;
		void setCodec(const VideoCodec &value);

		VideoInformation *Clone();
	};

	class AudioInformation
	{
	private:
//ORIGINAL LINE: private BitrateManagementMode[] _aBitrateModes;
//C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
		BitrateManagementMode *_aBitrateModes;
		std::vector<AudioTrackInfo*> _arrAudioTracks;
//ORIGINAL LINE: private AudioCodec[] _aCodecs;
//C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
		AudioCodec *_aCodecs;
		AudioType *_aType;

	public:
		AudioInformation();

		const AudioType &getType() const;
		void setType(const AudioType &value);

		const AudioCodec *getCodecs() const;
		void setCodecs(AudioCodec value[]);

		const BitrateManagementMode *getBitrateModes() const;
		void setBitrateModes(BitrateManagementMode value[]);

		const std::vector<AudioTrackInfo*> &getTracks() const;
		void setTracks(const std::vector<AudioTrackInfo*> &value);

		/// <summary>gets the first audio track ID for muxing with mkvmerge</summary>
		/// <returns>trackID or 0</returns>
		int GetFirstTrackID();

		/// <summary>gets the information if the file has as least one audio track</summary>
		/// <returns>true if the file has at least one audio track</returns>
		bool HasAudio();

		VideoInformation *Clone();

	private:
		void InitializeInstanceFields();
	};

	class SubtitleInformation
	{
	private:
		std::vector<SubtitleTrackInfo*> _arrSubtitleTracks;

	public:
		SubtitleInformation();

		const std::vector<SubtitleTrackInfo*> &getTracks() const;
		void setTracks(const std::vector<SubtitleTrackInfo*> &value);

		/// <summary>gets the first subtitle track ID for muxing with mkvmerge</summary>
		/// <returns>trackID or 0</returns>
		int GetFirstTrackID();

		VideoInformation *Clone();

	private:
		void InitializeInstanceFields();
	};
}
