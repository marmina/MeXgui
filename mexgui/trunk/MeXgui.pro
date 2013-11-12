######################################################################
# Automatically generated by qmake (2.01a) Thu Nov 7 18:27:30 2013
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . \
              core/details \
              core/gui \
              core/util \
              packages/audio \
              core/details/mux \
              core/details/video \
              core/gui/forms \
              core/plugins/implemented \
              core/plugins/interfaces \
              packages/audio/aften \
              packages/audio/ffac3 \
              packages/audio/ffmp2 \
              packages/audio/flac \
              packages/audio/lame \
              packages/audio/naac \
              packages/audio/opus \
              packages/audio/qaac \
              packages/audio/vorbis \
              packages/demuxer/mkvextract \
              packages/demuxer/pgcdemux \
              packages/muxer/avimuxgui \
              packages/muxer/mkvmerge \
              packages/muxer/mp4box \
              packages/muxer/tsmuxer \
              packages/reader/avs \
              packages/reader/d2v \
              packages/reader/dga \
              packages/reader/dgi \
              packages/reader/dvddecrypter \
              packages/reader/ffms \
              packages/reader/mediainfo \
              packages/reader/ttxt \
              packages/reader/video \
              packages/reader/vobsub \
              packages/tools/autoencode \
              packages/tools/avclevelschecker \
              packages/tools/avscreator \
              packages/tools/besplitter \
              packages/tools/calculator \
              packages/tools/chaptercreator \
              packages/tools/cqmeditor \
              packages/tools/cutter \
              packages/tools/fileindexer \
              packages/tools/hdbdextractor \
              packages/tools/oneclick \
              packages/tools/vobsub \
              packages/video/ffmpeg \
              packages/video/huffyuv \
              packages/video/x264 \
              packages/video/xvid \
              core/plugins/implemented/video \
              packages/tools/chaptercreator/BDInfo \
              packages/tools/hdbdextractor/eac3to
INCLUDEPATH += . \
               core/details \
               core/plugins/interfaces \
               core/util \
               core/gui \
               core/details/video \
               packages/tools/chaptercreator \
               packages/reader/video \
               packages/reader/avs \
               packages/tools/avscreator \
               packages/reader/mediainfo \
               packages/tools/calculator \
               core/details/mux \
               packages/tools/autoencode \
               packages/tools/fileindexer \
               packages/demuxer/pgcdemux \
               packages/demuxer/mkvextract \
               packages/muxer/mp4box \
               core/plugins/implemented \
               packages/reader/ttxt \
               packages/muxer/mkvmerge \
               packages/reader/vobsub \
               packages/muxer/avimuxgui \
               packages/muxer/tsmuxer \
               packages/audio \
               packages/audio/aften \
               packages/audio/ffac3 \
               packages/audio/ffmp2 \
               packages/audio/flac \
               packages/audio/lame \
               packages/audio/naac \
               packages/audio/opus \
               packages/audio/qaac \
               packages/audio/vorbis \
               packages/video/xvid \
               core/plugins/implemented/video \
               packages/video/x264 \
               packages/tools/avclevelschecker \
               packages/video/huffyuv \
               packages/reader/d2v \
               packages/tools/oneclick \
               packages/tools/chaptercreator/BDInfo \
               packages/tools/hdbdextractor \
               packages/tools/vobsub \
               packages/reader/dgi \
               packages/tools/hdbdextractor/eac3to \
               packages/video/ffmpeg \
               packages/reader/dga \
               packages/reader/ffms \
               packages/tools/besplitter \
               packages/tools/cutter \
               packages/tools/cqmeditor \
               packages/reader/dvddecrypter

# Input
HEADERS += AssemblyInfo.h \
           MeGUI.Properties.Settings.h \
           stringconverter.h \
           core/details/AudioTrackInfo.h \
           core/details/CleanupJob.h \
           core/details/CodecManager.h \
           core/details/CommandlineParser.h \
           core/details/DependencyChain.h \
           core/details/DialogManager.h \
           core/details/DialogSettings.h \
           core/details/JobControl.h \
           core/details/JobWorker.h \
           core/details/MediaFileFactory.h \
           core/details/MeGUI.core.details.JobChain.h \
           core/details/MeGUI.core.details.JobControl.h \
           core/details/MeGUI.core.details.ParallelChain.h \
           core/details/MeGUI.core.details.SequentialChain.h \
           core/details/MeGUISettings.h \
           core/details/PackageSystem.h \
           core/details/ProfileManager.h \
           core/details/StatusUpdate.h \
           core/details/Streams.h \
           core/details/SubtitleTrackInfo.h \
           core/details/TaggedJob.h \
           core/details/TrackInfo.h \
           core/details/VideoTrackInfo.h \
           core/gui/ARChooser.h \
           core/gui/FileBar.h \
           core/gui/FileSCBox.h \
           core/gui/FileSizeBar.h \
           core/gui/FPSChooser.h \
           core/gui/JobQueue.h \
           core/gui/JobWorker.h \
           core/gui/JobWorkerWindow.h \
           core/gui/MainForm.h \
           core/gui/MeGUI.AdaptiveMuxWindow.h \
           core/gui/MeGUI.AudioEncodingComponent.h \
           core/gui/MeGUI.core.gui.AspectRatioChooser.h \
           core/gui/MeGUI.core.gui.AudioEncodingTab.h \
           core/gui/MeGUI.core.gui.AudioEncodingWindow.h \
           core/gui/MeGUI.core.gui.AutoUpdateServerConfigWindow.h \
           core/gui/MeGUI.core.gui.ConfigableProfilesControl.h \
           core/gui/MeGUI.core.gui.CountdownWindow.h \
           core/gui/MeGUI.core.gui.FileSizeBar.h \
           core/gui/MeGUI.core.gui.FileSizeDialog.h \
           core/gui/MeGUI.core.gui.HelpButton.h \
           core/gui/MeGUI.core.gui.IndividualWorkerSummary.h \
           core/gui/MeGUI.core.gui.InputBox.h \
           core/gui/MeGUI.core.gui.JobQueue.h \
           core/gui/MeGUI.core.gui.JobWorker.h \
           core/gui/MeGUI.core.gui.LogTree.h \
           core/gui/MeGUI.core.gui.NiceComboBox.h \
           core/gui/MeGUI.core.gui.NumberChooser.h \
           "core/gui/MeGUI.core.gui.ProfileConfigurationWindow - generic 2.h" \
           core/gui/MeGUI.core.gui.ProfileExporter.h \
           core/gui/MeGUI.core.gui.ProfileImporter.h \
           core/gui/MeGUI.core.gui.ProfilePorter.h \
           core/gui/MeGUI.core.gui.SimpleProfilesControl.h \
           core/gui/MeGUI.core.gui.StandardAndCustomComboBox.h \
           core/gui/MeGUI.core.gui.TextViewer.h \
           core/gui/MeGUI.core.gui.VideoPlayerControl.h \
           core/gui/MeGUI.core.gui.WorkerSummary.h \
           core/gui/MeGUI.core.gui.ZonesWindow.h \
           core/gui/MeGUI.FileBar.h \
           core/gui/MeGUI.MainForm.h \
           core/gui/MeGUI.ProgressWindow.h \
           core/gui/MeGUI.SourceDetectorConfigWindow.h \
           core/gui/MeGUI.UpdateWindow.h \
           core/gui/MeGUI.ZonesControl.h \
           core/gui/NiceComboBox.h \
           core/gui/ProfileImporter.h \
           core/gui/Profiles.h \
           core/gui/ProgressTaskbar.h \
           core/gui/ProgressWindow.h \
           core/gui/ProgressWindowInfo.h \
           core/gui/SettingsForm.h \
           core/gui/SimpleProfilesControl.h \
           core/gui/SourceDetector.h \
           core/gui/SourceDetectorSettings.h \
           core/gui/StandardAndCustomComboBox.h \
           core/gui/TargetSizeSCBox.h \
           core/gui/UpdateCacher.h \
           core/gui/UpdateWindow.h \
           core/gui/VideoPlayer.h \
           core/util/AudioUtil.h \
           core/util/Autocrop.h \
           core/util/BitrateCalculatorPreProcessor.h \
           core/util/DAR.h \
           core/util/DeinterlaceFilter.h \
           core/util/DirectShow.h \
           core/util/DragDropUtil.h \
           core/util/Drives.h \
           core/util/EnumProxy.h \
           core/util/Exceptions.h \
           core/util/FileSize.h \
           core/util/FileUtil.h \
           core/util/FilmCutter.h \
           core/util/GenericRegisterer.h \
           core/util/HttpProxy.h \
           core/util/IFOparser.h \
           core/util/JobUtil.h \
           core/util/LanguageSelectionContainer.h \
           core/util/LogItem.h \
           core/util/NotifyCounter.h \
           core/util/OSInfo.h \
           core/util/PrettyFormatting.h \
           core/util/Resolution.h \
           core/util/Shutdown.h \
           core/util/Tuples.h \
           core/util/Util.h \
           core/util/VideoUtil.h \
           core/util/VistaStuff.h \
           core/util/WindowUtil.h \
           packages/audio/AudioCodecSettings.h \
           packages/audio/AudioEncoderInterface.h \
           packages/audio/AudioJob.h \
           packages/audio/MeGUI.core.details.audio.AudioConfigurationPanel.h \
           core/details/mux/baseMuxWindow.h \
           core/details/mux/MeGUI.core.details.mux.MuxStreamControl.h \
           core/details/mux/MeGUI.MuxWindow.h \
           core/details/mux/MuxJob.h \
           core/details/mux/MuxPath.h \
           core/details/mux/MuxPathComparer.h \
           core/details/mux/MuxProvider.h \
           core/details/mux/MuxSettings.h \
           core/details/video/MeGUI.VideoEncodingComponent.h \
           core/details/video/VideoCodecSettings.h \
           core/details/video/VideoConfigurationPanel.h \
           core/details/video/VideoJob.h \
           core/plugins/implemented/CommandlineJobProcessor.h \
           core/plugins/implemented/CommandlineMuxer.h \
           core/plugins/interfaces/IJobProcessor.h \
           core/plugins/interfaces/IMediaFile.h \
           core/plugins/interfaces/IMuxing.h \
           core/plugins/interfaces/IPackage.h \
           core/plugins/interfaces/ISettingsProvider.h \
           core/plugins/interfaces/Job.h \
           core/plugins/interfaces/JobProcessorManager.h \
           core/plugins/interfaces/Profile.h \
           packages/audio/aften/AftenSettings.h \
           packages/audio/aften/MeGUI.packages.audio.aften.AftenConfigurationPanel.h \
           packages/audio/ffac3/AC3Settings.h \
           packages/audio/ffac3/MeGUI.packages.audio.ffac3.AC3ConfigurationPanel.h \
           packages/audio/ffmp2/MeGUI.packages.audio.ffmp2.MP2ConfigurationPanel.h \
           packages/audio/ffmp2/MP2Settings.h \
           packages/audio/flac/FlacSettings.h \
           packages/audio/flac/MeGUI.packages.audio.flac.FlacConfigurationPanel.h \
           packages/audio/lame/MeGUI.packages.audio.lame.lameConfigurationPanel.h \
           packages/audio/lame/MP3Settings.h \
           packages/audio/naac/MeGUI.packages.audio.naac.neroConfigurationPanel.h \
           packages/audio/naac/NeroAACSettings.h \
           packages/audio/opus/MeGUI.packages.audio.opus.OpusConfigurationPanel.h \
           packages/audio/opus/OpusSettings.h \
           packages/audio/qaac/MeGUI.packages.audio.qaac.qaacConfigurationPanel.h \
           packages/audio/qaac/QaacSettings.h \
           packages/audio/vorbis/MeGUI.packages.audio.vorbis.OggVorbisConfigurationPanel.h \
           packages/audio/vorbis/OggVorbisSettings.h \
           packages/demuxer/mkvextract/MkvExtract.h \
           packages/demuxer/mkvextract/MkvExtractJob.h \
           packages/demuxer/mkvextract/MkvInfo.h \
           packages/demuxer/mkvextract/MkvInfoTrack.h \
           packages/demuxer/pgcdemux/PgcDemux.h \
           packages/demuxer/pgcdemux/PgcDemuxJob.h \
           packages/muxer/avimuxgui/AMGMuxer.h \
           packages/muxer/mkvmerge/MkvMergeMuxer.h \
           packages/muxer/mp4box/MP4BoxMuxer.h \
           packages/muxer/tsmuxer/tsMuxeR.h \
           packages/reader/avs/AvsReader.h \
           packages/reader/d2v/d2vReader.h \
           packages/reader/dga/dgaReader.h \
           packages/reader/dgi/dgiReader.h \
           packages/reader/dvddecrypter/DVDD_File.h \
           packages/reader/ffms/ffmsReader.h \
           packages/reader/mediainfo/MediaInfoFile.h \
           packages/reader/ttxt/ttxtReader.h \
           packages/reader/video/VideoReader.h \
           packages/reader/vobsub/idxReader.h \
           packages/tools/autoencode/AutoEncodeDefaultsSettings.h \
           packages/tools/autoencode/AutoEncodeWindow.h \
           packages/tools/autoencode/MeGUI.AutoEncodeDefaults.h \
           packages/tools/avclevelschecker/AVCLevels.h \
           packages/tools/avscreator/AviSynthJob.h \
           packages/tools/avscreator/AviSynthProcessor.h \
           packages/tools/avscreator/AviSynthSettings.h \
           packages/tools/avscreator/AviSynthWindow.h \
           packages/tools/avscreator/AvisynthWrapper.h \
           packages/tools/avscreator/MeGUI.AviSynthWindow.h \
           packages/tools/avscreator/MeGUI.core.gui.AviSynthProfileConfigPanel.h \
           packages/tools/avscreator/ScriptServer.h \
           packages/tools/besplitter/AudioJoinJob.h \
           packages/tools/besplitter/AudioSplitJob.h \
           packages/tools/besplitter/Besplitter.h \
           packages/tools/besplitter/Joiner.h \
           packages/tools/besplitter/MeGUI.packages.tools.besplitter.Besplitter.h \
           packages/tools/besplitter/Splitter.h \
           packages/tools/calculator/CalcData.h \
           packages/tools/calculator/Calculator.h \
           packages/tools/calculator/MeGUI.Calculator.h \
           packages/tools/calculator/MeGUI.packages.tools.calculator.AudioTrackSizeTab.h \
           packages/tools/calculator/MeGUI.packages.tools.calculator.ExtraSizeTab.h \
           packages/tools/chaptercreator/BDInfoExtractor.h \
           packages/tools/chaptercreator/BlurayExtractor.h \
           packages/tools/chaptercreator/ChapterCreator.h \
           packages/tools/chaptercreator/ChapterExtractor.h \
           packages/tools/chaptercreator/ChapterInfo.h \
           packages/tools/chaptercreator/DvdExtractor.h \
           packages/tools/chaptercreator/IfoExtractor.h \
           packages/tools/chaptercreator/MeGUI.frmStreamSelect.h \
           packages/tools/chaptercreator/MplsExtractor.h \
           packages/tools/chaptercreator/TextExtractor.h \
           packages/tools/cqmeditor/QuantizerMatrixDialog.h \
           packages/tools/cutter/Cutter.h \
           packages/tools/cutter/MeGUI.packages.tools.cutter.Cutter.h \
           packages/tools/fileindexer/D2VIndexer.h \
           packages/tools/fileindexer/D2VIndexJob.h \
           packages/tools/fileindexer/DGAIndexer.h \
           packages/tools/fileindexer/DGAIndexJob.h \
           packages/tools/fileindexer/DGIIndexer.h \
           packages/tools/fileindexer/DGIIndexJob.h \
           packages/tools/fileindexer/FFMSIndexer.h \
           packages/tools/fileindexer/FFMSIndexJob.h \
           packages/tools/fileindexer/FileIndexerWindow.h \
           packages/tools/fileindexer/IndexJob.h \
           packages/tools/fileindexer/MeGUI.FileIndexerWindow.h \
           packages/tools/hdbdextractor/CustomDataGridView.h \
           packages/tools/hdbdextractor/Eac3ToInfo.h \
           packages/tools/hdbdextractor/Extensions.h \
           packages/tools/hdbdextractor/HDBDStreamExtractor.h \
           packages/tools/hdbdextractor/HDStreamExtractorIndexer.h \
           packages/tools/hdbdextractor/HDStreamsExJob.h \
           packages/tools/hdbdextractor/MeGUI.packages.tools.hdbdextractor.HdBdStreamExtractor.h \
           packages/tools/oneclick/MeGUI.OneClickAudioControl.h \
           packages/tools/oneclick/MeGUI.OneClickStreamControl.h \
           packages/tools/oneclick/MeGUI.OneClickWindow.h \
           packages/tools/oneclick/MeGUI.packages.tools.oneclick.AudioConfigControl.h \
           packages/tools/oneclick/MeGUI.packages.tools.oneclick.OneClickConfigPanel.h \
           packages/tools/oneclick/OneClickAudioControl.h \
           packages/tools/oneclick/OneClickAudioTrack.h \
           packages/tools/oneclick/OneClickPostProcessing.h \
           packages/tools/oneclick/OneClickPostProcessingJob.h \
           packages/tools/oneclick/OneClickPostprocessingProperties.h \
           packages/tools/oneclick/OneClickProcessing.h \
           packages/tools/oneclick/OneClickSettings.h \
           packages/tools/oneclick/OneClickStream.h \
           packages/tools/oneclick/OneClickWindow.h \
           packages/tools/vobsub/MeGUI.VobSubIndexWindow.h \
           packages/tools/vobsub/SubtitleIndexJob.h \
           packages/tools/vobsub/VobSubIndexer.h \
           packages/tools/vobsub/VobSubIndexWindow.h \
           packages/video/ffmpeg/ffmpegEncoder.h \
           packages/video/huffyuv/hfyuSettings.h \
           packages/video/x264/MeGUI.packages.video.x264.x264ConfigurationPanel.h \
           packages/video/x264/x264Device.h \
           packages/video/x264/x264Encoder.h \
           packages/video/x264/x264Settings.h \
           packages/video/x264/x264SettingsHandler.h \
           packages/video/xvid/MeGUI.packages.video.xvid.xvidConfigurationPanel.h \
           packages/video/xvid/XviDEncoder.h \
           packages/video/xvid/xvidSettings.h \
           core/plugins/implemented/video/CommandlineVideoEncoder.h \
           packages/tools/chaptercreator/BDInfo/LanguageCodes.h \
           packages/tools/chaptercreator/BDInfo/TSPlaylistFile.h \
           packages/tools/chaptercreator/BDInfo/TSStream.h \
           packages/tools/chaptercreator/BDInfo/TSStreamClip.h \
           packages/tools/chaptercreator/BDInfo/TSStreamClipFile.h \
           packages/tools/hdbdextractor/eac3to/AudioStream.h \
           packages/tools/hdbdextractor/eac3to/AudioStreamType.h \
           packages/tools/hdbdextractor/eac3to/Chapter.h \
           packages/tools/hdbdextractor/eac3to/ChapterStream.h \
           packages/tools/hdbdextractor/eac3to/Feature.h \
           packages/tools/hdbdextractor/eac3to/File.h \
           packages/tools/hdbdextractor/eac3to/JoinStream.h \
           packages/tools/hdbdextractor/eac3to/Stream.h \
           packages/tools/hdbdextractor/eac3to/StreamType.h \
           packages/tools/hdbdextractor/eac3to/SubtitleStream.h \
           packages/tools/hdbdextractor/eac3to/VideoStream.h \
           packages/tools/hdbdextractor/eac3to/VideoStreamType.h
FORMS += core/gui/forms/config_audio.ui \
         core/gui/forms/config_neroaac.ui \
         core/gui/forms/config_x264.ui \
         core/gui/forms/MainForm.ui
SOURCES += AssemblyInfo.cpp \
           MeGUI.Properties.Settings.cpp \
           core/details/AudioTrackInfo.cpp \
           core/details/CleanupJob.cpp \
           core/details/CodecManager.cpp \
           core/details/CommandlineParser.cpp \
           core/details/DependencyChain.cpp \
           core/details/DialogManager.cpp \
           core/details/DialogSettings.cpp \
           core/details/JobControl.cpp \
           core/details/JobWorker.cpp \
           core/details/MediaFileFactory.cpp \
           core/details/MeGUI.core.details.JobChain.cpp \
           core/details/MeGUI.core.details.JobControl.cpp \
           core/details/MeGUI.core.details.ParallelChain.cpp \
           core/details/MeGUI.core.details.SequentialChain.cpp \
           core/details/MeGUISettings.cpp \
           core/details/PackageSystem.cpp \
           core/details/ProfileManager.cpp \
           core/details/StatusUpdate.cpp \
           core/details/Streams.cpp \
           core/details/SubtitleTrackInfo.cpp \
           core/details/TaggedJob.cpp \
           core/details/TrackInfo.cpp \
           core/details/VideoTrackInfo.cpp \
           core/gui/ARChooser.cpp \
           core/gui/FileBar.cpp \
           core/gui/FileSCBox.cpp \
           core/gui/FileSizeBar.cpp \
           core/gui/FPSChooser.cpp \
           core/gui/JobQueue.cpp \
           core/gui/JobWorker.cpp \
           core/gui/JobWorkerWindow.cpp \
           core/gui/MainForm.cpp \
           core/gui/MeGUI.AdaptiveMuxWindow.cpp \
           core/gui/MeGUI.AudioEncodingComponent.cpp \
           core/gui/MeGUI.core.gui.AspectRatioChooser.cpp \
           core/gui/MeGUI.core.gui.AudioEncodingTab.cpp \
           core/gui/MeGUI.core.gui.AudioEncodingWindow.cpp \
           core/gui/MeGUI.core.gui.AutoUpdateServerConfigWindow.cpp \
           core/gui/MeGUI.core.gui.ConfigableProfilesControl.cpp \
           core/gui/MeGUI.core.gui.CountdownWindow.cpp \
           core/gui/MeGUI.core.gui.FileSizeBar.cpp \
           core/gui/MeGUI.core.gui.FileSizeDialog.cpp \
           core/gui/MeGUI.core.gui.HelpButton.cpp \
           core/gui/MeGUI.core.gui.IndividualWorkerSummary.cpp \
           core/gui/MeGUI.core.gui.InputBox.cpp \
           core/gui/MeGUI.core.gui.JobQueue.cpp \
           core/gui/MeGUI.core.gui.JobWorker.cpp \
           core/gui/MeGUI.core.gui.LogTree.cpp \
           core/gui/MeGUI.core.gui.NiceComboBox.cpp \
           core/gui/MeGUI.core.gui.NumberChooser.cpp \
           "core/gui/MeGUI.core.gui.ProfileConfigurationWindow - generic 2.cpp" \
           core/gui/MeGUI.core.gui.ProfileExporter.cpp \
           core/gui/MeGUI.core.gui.ProfileImporter.cpp \
           core/gui/MeGUI.core.gui.ProfilePorter.cpp \
           core/gui/MeGUI.core.gui.SimpleProfilesControl.cpp \
           core/gui/MeGUI.core.gui.StandardAndCustomComboBox.cpp \
           core/gui/MeGUI.core.gui.TextViewer.cpp \
           core/gui/MeGUI.core.gui.VideoPlayerControl.cpp \
           core/gui/MeGUI.core.gui.WorkerSummary.cpp \
           core/gui/MeGUI.core.gui.ZonesWindow.cpp \
           core/gui/MeGUI.FileBar.cpp \
           core/gui/MeGUI.MainForm.cpp \
           core/gui/MeGUI.ProgressWindow.cpp \
           core/gui/MeGUI.SourceDetectorConfigWindow.cpp \
           core/gui/MeGUI.UpdateWindow.cpp \
           core/gui/MeGUI.ZonesControl.cpp \
           core/gui/NiceComboBox.cpp \
           core/gui/ProfileImporter.cpp \
           core/gui/Profiles.cpp \
           core/gui/ProgressTaskbar.cpp \
           core/gui/ProgressWindow.cpp \
           core/gui/ProgressWindowInfo.cpp \
           core/gui/SettingsForm.cpp \
           core/gui/SimpleProfilesControl.cpp \
           core/gui/SourceDetector.cpp \
           core/gui/SourceDetectorSettings.cpp \
           core/gui/StandardAndCustomComboBox.cpp \
           core/gui/TargetSizeSCBox.cpp \
           core/gui/UpdateCacher.cpp \
           core/gui/UpdateWindow.cpp \
           core/gui/VideoPlayer.cpp \
           core/util/AudioUtil.cpp \
           core/util/Autocrop.cpp \
           core/util/BitrateCalculatorPreProcessor.cpp \
           core/util/DAR.cpp \
           core/util/DeinterlaceFilter.cpp \
           core/util/DirectShow.cpp \
           core/util/DragDropUtil.cpp \
           core/util/Drives.cpp \
           core/util/EnumProxy.cpp \
           core/util/Exceptions.cpp \
           core/util/FileSize.cpp \
           core/util/FileUtil.cpp \
           core/util/FilmCutter.cpp \
           core/util/GenericRegisterer.cpp \
           core/util/HttpProxy.cpp \
           core/util/IFOparser.cpp \
           core/util/JobUtil.cpp \
           core/util/LanguageSelectionContainer.cpp \
           core/util/LogItem.cpp \
           core/util/NotifyCounter.cpp \
           core/util/OSInfo.cpp \
           core/util/PrettyFormatting.cpp \
           core/util/Resolution.cpp \
           core/util/Shutdown.cpp \
           core/util/Tuples.cpp \
           core/util/Util.cpp \
           core/util/VideoUtil.cpp \
           core/util/VistaStuff.cpp \
           core/util/WindowUtil.cpp \
           packages/audio/AudioCodecSettings.cpp \
           packages/audio/AudioEncoderInterface.cpp \
           packages/audio/AudioJob.cpp \
           packages/audio/MeGUI.core.details.audio.AudioConfigurationPanel.cpp \
           core/details/mux/baseMuxWindow.cpp \
           core/details/mux/MeGUI.core.details.mux.MuxStreamControl.cpp \
           core/details/mux/MeGUI.MuxWindow.cpp \
           core/details/mux/MuxJob.cpp \
           core/details/mux/MuxPath.cpp \
           core/details/mux/MuxPathComparer.cpp \
           core/details/mux/MuxProvider.cpp \
           core/details/mux/MuxSettings.cpp \
           core/details/video/MeGUI.VideoEncodingComponent.cpp \
           core/details/video/VideoCodecSettings.cpp \
           core/details/video/VideoConfigurationPanel.cpp \
           core/details/video/VideoJob.cpp \
           core/plugins/implemented/CommandlineJobProcessor.cpp \
           core/plugins/implemented/CommandlineMuxer.cpp \
           core/plugins/interfaces/IJobProcessor.cpp \
           core/plugins/interfaces/IMediaFile.cpp \
           core/plugins/interfaces/IMuxing.cpp \
           core/plugins/interfaces/IPackage.cpp \
           core/plugins/interfaces/ISettingsProvider.cpp \
           core/plugins/interfaces/Job.cpp \
           core/plugins/interfaces/JobProcessorManager.cpp \
           core/plugins/interfaces/Profile.cpp \
           packages/audio/aften/AftenSettings.cpp \
           packages/audio/aften/MeGUI.packages.audio.aften.AftenConfigurationPanel.cpp \
           packages/audio/ffac3/AC3Settings.cpp \
           packages/audio/ffac3/MeGUI.packages.audio.ffac3.AC3ConfigurationPanel.cpp \
           packages/audio/ffmp2/MeGUI.packages.audio.ffmp2.MP2ConfigurationPanel.cpp \
           packages/audio/ffmp2/MP2Settings.cpp \
           packages/audio/flac/FlacSettings.cpp \
           packages/audio/flac/MeGUI.packages.audio.flac.FlacConfigurationPanel.cpp \
           packages/audio/lame/MeGUI.packages.audio.lame.lameConfigurationPanel.cpp \
           packages/audio/lame/MP3Settings.cpp \
           packages/audio/naac/MeGUI.packages.audio.naac.neroConfigurationPanel.cpp \
           packages/audio/naac/NeroAACSettings.cpp \
           packages/audio/opus/MeGUI.packages.audio.opus.OpusConfigurationPanel.cpp \
           packages/audio/opus/OpusSettings.cpp \
           packages/audio/qaac/MeGUI.packages.audio.qaac.qaacConfigurationPanel.cpp \
           packages/audio/qaac/QaacSettings.cpp \
           packages/audio/vorbis/MeGUI.packages.audio.vorbis.OggVorbisConfigurationPanel.cpp \
           packages/audio/vorbis/OggVorbisSettings.cpp \
           packages/demuxer/mkvextract/MkvExtract.cpp \
           packages/demuxer/mkvextract/MkvExtractJob.cpp \
           packages/demuxer/mkvextract/MkvInfo.cpp \
           packages/demuxer/mkvextract/MkvInfoTrack.cpp \
           packages/demuxer/pgcdemux/PgcDemux.cpp \
           packages/demuxer/pgcdemux/PgcDemuxJob.cpp \
           packages/muxer/avimuxgui/AMGMuxer.cpp \
           packages/muxer/mkvmerge/MkvMergeMuxer.cpp \
           packages/muxer/mp4box/MP4BoxMuxer.cpp \
           packages/muxer/tsmuxer/tsMuxeR.cpp \
           packages/reader/avs/AvsReader.cpp \
           packages/reader/d2v/d2vReader.cpp \
           packages/reader/dga/dgaReader.cpp \
           packages/reader/dgi/dgiReader.cpp \
           packages/reader/dvddecrypter/DVDD_File.cpp \
           packages/reader/ffms/ffmsReader.cpp \
           packages/reader/mediainfo/MediaInfoFile.cpp \
           packages/reader/ttxt/ttxtReader.cpp \
           packages/reader/video/VideoReader.cpp \
           packages/reader/vobsub/idxReader.cpp \
           packages/tools/autoencode/AutoEncodeDefaultsSettings.cpp \
           packages/tools/autoencode/AutoEncodeWindow.cpp \
           packages/tools/autoencode/MeGUI.AutoEncodeDefaults.cpp \
           packages/tools/avclevelschecker/AVCLevels.cpp \
           packages/tools/avscreator/AviSynthJob.cpp \
           packages/tools/avscreator/AviSynthProcessor.cpp \
           packages/tools/avscreator/AviSynthSettings.cpp \
           packages/tools/avscreator/AviSynthWindow.cpp \
           packages/tools/avscreator/AvisynthWrapper.cpp \
           packages/tools/avscreator/MeGUI.AviSynthWindow.cpp \
           packages/tools/avscreator/MeGUI.core.gui.AviSynthProfileConfigPanel.cpp \
           packages/tools/avscreator/ScriptServer.cpp \
           packages/tools/besplitter/AudioJoinJob.cpp \
           packages/tools/besplitter/AudioSplitJob.cpp \
           packages/tools/besplitter/Besplitter.cpp \
           packages/tools/besplitter/Joiner.cpp \
           packages/tools/besplitter/MeGUI.packages.tools.besplitter.Besplitter.cpp \
           packages/tools/besplitter/Splitter.cpp \
           packages/tools/calculator/CalcData.cpp \
           packages/tools/calculator/Calculator.cpp \
           packages/tools/calculator/MeGUI.Calculator.cpp \
           packages/tools/calculator/MeGUI.packages.tools.calculator.AudioTrackSizeTab.cpp \
           packages/tools/calculator/MeGUI.packages.tools.calculator.ExtraSizeTab.cpp \
           packages/tools/chaptercreator/BDInfoExtractor.cpp \
           packages/tools/chaptercreator/BlurayExtractor.cpp \
           packages/tools/chaptercreator/ChapterCreator.cpp \
           packages/tools/chaptercreator/ChapterExtractor.cpp \
           packages/tools/chaptercreator/ChapterInfo.cpp \
           packages/tools/chaptercreator/DvdExtractor.cpp \
           packages/tools/chaptercreator/IfoExtractor.cpp \
           packages/tools/chaptercreator/MeGUI.frmStreamSelect.cpp \
           packages/tools/chaptercreator/MplsExtractor.cpp \
           packages/tools/chaptercreator/TextExtractor.cpp \
           packages/tools/cqmeditor/QuantizerMatrixDialog.cpp \
           packages/tools/cutter/Cutter.cpp \
           packages/tools/cutter/MeGUI.packages.tools.cutter.Cutter.cpp \
           packages/tools/fileindexer/D2VIndexer.cpp \
           packages/tools/fileindexer/D2VIndexJob.cpp \
           packages/tools/fileindexer/DGAIndexer.cpp \
           packages/tools/fileindexer/DGAIndexJob.cpp \
           packages/tools/fileindexer/DGIIndexer.cpp \
           packages/tools/fileindexer/DGIIndexJob.cpp \
           packages/tools/fileindexer/FFMSIndexer.cpp \
           packages/tools/fileindexer/FFMSIndexJob.cpp \
           packages/tools/fileindexer/FileIndexerWindow.cpp \
           packages/tools/fileindexer/IndexJob.cpp \
           packages/tools/fileindexer/MeGUI.FileIndexerWindow.cpp \
           packages/tools/hdbdextractor/CustomDataGridView.cpp \
           packages/tools/hdbdextractor/Eac3ToInfo.cpp \
           packages/tools/hdbdextractor/Extensions.cpp \
           packages/tools/hdbdextractor/HDBDStreamExtractor.cpp \
           packages/tools/hdbdextractor/HDStreamExtractorIndexer.cpp \
           packages/tools/hdbdextractor/HDStreamsExJob.cpp \
           packages/tools/hdbdextractor/MeGUI.packages.tools.hdbdextractor.HdBdStreamExtractor.cpp \
           packages/tools/oneclick/MeGUI.OneClickAudioControl.cpp \
           packages/tools/oneclick/MeGUI.OneClickStreamControl.cpp \
           packages/tools/oneclick/MeGUI.OneClickWindow.cpp \
           packages/tools/oneclick/MeGUI.packages.tools.oneclick.AudioConfigControl.cpp \
           packages/tools/oneclick/MeGUI.packages.tools.oneclick.OneClickConfigPanel.cpp \
           packages/tools/oneclick/OneClickAudioControl.cpp \
           packages/tools/oneclick/OneClickAudioTrack.cpp \
           packages/tools/oneclick/OneClickPostProcessing.cpp \
           packages/tools/oneclick/OneClickPostProcessingJob.cpp \
           packages/tools/oneclick/OneClickPostprocessingProperties.cpp \
           packages/tools/oneclick/OneClickProcessing.cpp \
           packages/tools/oneclick/OneClickSettings.cpp \
           packages/tools/oneclick/OneClickStream.cpp \
           packages/tools/oneclick/OneClickWindow.cpp \
           packages/tools/vobsub/MeGUI.VobSubIndexWindow.cpp \
           packages/tools/vobsub/SubtitleIndexJob.cpp \
           packages/tools/vobsub/VobSubIndexer.cpp \
           packages/tools/vobsub/VobSubIndexWindow.cpp \
           packages/video/ffmpeg/ffmpegEncoder.cpp \
           packages/video/huffyuv/hfyuSettings.cpp \
           packages/video/x264/MeGUI.packages.video.x264.x264ConfigurationPanel.cpp \
           packages/video/x264/x264Device.cpp \
           packages/video/x264/x264Encoder.cpp \
           packages/video/x264/x264Settings.cpp \
           packages/video/x264/x264SettingsHandler.cpp \
           packages/video/xvid/MeGUI.packages.video.xvid.xvidConfigurationPanel.cpp \
           packages/video/xvid/XviDEncoder.cpp \
           packages/video/xvid/xvidSettings.cpp \
           core/plugins/implemented/video/CommandlineVideoEncoder.cpp \
           packages/tools/chaptercreator/BDInfo/LanguageCodes.cpp \
           packages/tools/chaptercreator/BDInfo/TSPlaylistFile.cpp \
           packages/tools/chaptercreator/BDInfo/TSStream.cpp \
           packages/tools/chaptercreator/BDInfo/TSStreamClip.cpp \
           packages/tools/chaptercreator/BDInfo/TSStreamClipFile.cpp \
           packages/tools/hdbdextractor/eac3to/AudioStream.cpp \
           packages/tools/hdbdextractor/eac3to/AudioStreamType.cpp \
           packages/tools/hdbdextractor/eac3to/Chapter.cpp \
           packages/tools/hdbdextractor/eac3to/ChapterStream.cpp \
           packages/tools/hdbdextractor/eac3to/Feature.cpp \
           packages/tools/hdbdextractor/eac3to/File.cpp \
           packages/tools/hdbdextractor/eac3to/JoinStream.cpp \
           packages/tools/hdbdextractor/eac3to/Stream.cpp \
           packages/tools/hdbdextractor/eac3to/StreamType.cpp \
           packages/tools/hdbdextractor/eac3to/SubtitleStream.cpp \
           packages/tools/hdbdextractor/eac3to/VideoStream.cpp \
           packages/tools/hdbdextractor/eac3to/VideoStreamType.cpp