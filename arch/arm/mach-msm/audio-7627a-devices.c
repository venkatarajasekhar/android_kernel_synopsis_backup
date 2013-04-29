/* Copyright (c) 2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <mach/board.h>

#include "board-msm7627a.h"

#define SND(desc, num) { .name = #desc, .id = num }
static struct snd_endpoint snd_endpoints_list[] = {
	SND(HANDSET, 0),
	SND(MONO_HEADSET, 2),
	SND(HEADSET, 3),
	SND(SPEAKER, 6),
	SND(TTY_HEADSET, 8),
	SND(TTY_VCO, 9),
	SND(TTY_HCO, 10),
	SND(BT, 12),
	SND(IN_S_SADC_OUT_HANDSET, 16),
	SND(IN_S_SADC_OUT_SPEAKER_PHONE, 25),
	SND(FM_DIGITAL_STEREO_HEADSET, 26),
	SND(FM_DIGITAL_SPEAKER_PHONE, 27),
	SND(FM_DIGITAL_BT_A2DP_HEADSET, 28),
	SND(STEREO_HEADSET_AND_SPEAKER, 31),
	SND(CURRENT, 0x7FFFFFFE),
	/* add new device for FM AUX_PGA path */
	SND(FM_RADIO_STEREO_HEADSET, 29),
	SND(FM_RADIO_SPEAKER_PHONE, 30),	
	SND(FM_ANALOG_STEREO_HEADSET, 35),
	SND(FM_ANALOG_STEREO_HEADSET_CODEC, 36),
	/* add new device for 2nd mic MMI test*/
	SND(HANDSET_2NDMIC, 37),
	/* add hac device for handset and handset_dualmic*/
	SND(HANDSET_HAC, 38),
	SND(IN_S_SADC_OUT_HANDSET_HAC, 39),
	SND(STEREO_SPEAKER, 40),
	SND(FM_RADIO_STEREO_SPEAKER_PHONE, 41),
	SND(STEREO_HEADSET_AND_STEREO_SPEAKER,42),
	SND(MTK_HANDSET, 43),
	SND(MTK_HEADSET, 44),
	SND(MTK_SPEAKER, 45),
	SND(MTK_BT, 46),	
    SND(MMI_BTLOOP_MTK, 47),
	SND(MMI_BTLOOP_QCOM, 48),
	SND(MTK_HANDSET_MUSIC, 49),
	SND(MTK_HEADSET_MUSIC, 50),
	SND(MTK_SPEAKER_MUSIC, 51),
	SND(MMI_HEADSETMIC_STEREO_SPEAKER, 52),
	SND(MMI_HEADSETMIC_HANDSET, 53),
	SND(MMI_MAINMIC_HEADSET, 54),
	SND(MMI_SUBMIC_HEADSET, 55),
	SND(MMI_HEADSETMIC_SPEAKER, 56)
};
#undef SND

static struct msm_snd_endpoints msm_device_snd_endpoints = {
	.endpoints = snd_endpoints_list,
	.num = sizeof(snd_endpoints_list) / sizeof(struct snd_endpoint)
};

struct platform_device msm_device_snd = {
	.name = "msm_snd",
	.id = -1,
	.dev    = {
		.platform_data = &msm_device_snd_endpoints
	},
};

#define DEC0_FORMAT ((1<<MSM_ADSP_CODEC_MP3)| \
	(1<<MSM_ADSP_CODEC_AAC)|(1<<MSM_ADSP_CODEC_WMA)| \
	(1<<MSM_ADSP_CODEC_WMAPRO)|(1<<MSM_ADSP_CODEC_AMRWB)| \
	(1<<MSM_ADSP_CODEC_AMRNB)|(1<<MSM_ADSP_CODEC_WAV)| \
	(1<<MSM_ADSP_CODEC_ADPCM)|(1<<MSM_ADSP_CODEC_YADPCM)| \
	(1<<MSM_ADSP_CODEC_EVRC)|(1<<MSM_ADSP_CODEC_QCELP)| \
	(1<<MSM_ADSP_CODEC_AC3))
#define DEC1_FORMAT ((1<<MSM_ADSP_CODEC_MP3)| \
	(1<<MSM_ADSP_CODEC_AAC)|(1<<MSM_ADSP_CODEC_WMA)| \
	(1<<MSM_ADSP_CODEC_WMAPRO)|(1<<MSM_ADSP_CODEC_AMRWB)| \
	(1<<MSM_ADSP_CODEC_AMRNB)|(1<<MSM_ADSP_CODEC_WAV)| \
	(1<<MSM_ADSP_CODEC_ADPCM)|(1<<MSM_ADSP_CODEC_YADPCM)| \
	(1<<MSM_ADSP_CODEC_EVRC)|(1<<MSM_ADSP_CODEC_QCELP))
#define DEC2_FORMAT ((1<<MSM_ADSP_CODEC_MP3)| \
	(1<<MSM_ADSP_CODEC_AAC)|(1<<MSM_ADSP_CODEC_WMA)| \
	(1<<MSM_ADSP_CODEC_WMAPRO)|(1<<MSM_ADSP_CODEC_AMRWB)| \
	(1<<MSM_ADSP_CODEC_AMRNB)|(1<<MSM_ADSP_CODEC_WAV)| \
	(1<<MSM_ADSP_CODEC_ADPCM)|(1<<MSM_ADSP_CODEC_YADPCM)| \
	(1<<MSM_ADSP_CODEC_EVRC)|(1<<MSM_ADSP_CODEC_QCELP))
#define DEC3_FORMAT ((1<<MSM_ADSP_CODEC_MP3)| \
	(1<<MSM_ADSP_CODEC_AAC)|(1<<MSM_ADSP_CODEC_WMA)| \
	(1<<MSM_ADSP_CODEC_WMAPRO)|(1<<MSM_ADSP_CODEC_AMRWB)| \
	(1<<MSM_ADSP_CODEC_AMRNB)|(1<<MSM_ADSP_CODEC_WAV)| \
	(1<<MSM_ADSP_CODEC_ADPCM)|(1<<MSM_ADSP_CODEC_YADPCM)| \
	(1<<MSM_ADSP_CODEC_EVRC)|(1<<MSM_ADSP_CODEC_QCELP))
#define DEC4_FORMAT (1<<MSM_ADSP_CODEC_MIDI)

static unsigned int dec_concurrency_table[] = {
	/* Audio LP */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DMA)), 0,
	0, 0, 0,

	/* Concurrency 1 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),

	 /* Concurrency 2 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),

	/* Concurrency 3 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),

	/* Concurrency 4 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),

	/* Concurrency 5 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),

	/* Concurrency 6 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|
			(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	0, 0, 0, 0,

	/* Concurrency 7 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),
};

#define DEC_INFO(name, queueid, decid, nr_codec) { .module_name = name, \
	.module_queueid = queueid, .module_decid = decid, \
	.nr_codec_support = nr_codec}

static struct msm_adspdec_info dec_info_list[] = {
	DEC_INFO("AUDPLAY0TASK", 13, 0, 11), /* AudPlay0BitStreamCtrlQueue */
	DEC_INFO("AUDPLAY1TASK", 14, 1, 11),  /* AudPlay1BitStreamCtrlQueue */
	DEC_INFO("AUDPLAY2TASK", 15, 2, 11),  /* AudPlay2BitStreamCtrlQueue */
	DEC_INFO("AUDPLAY3TASK", 16, 3, 11),  /* AudPlay3BitStreamCtrlQueue */
	DEC_INFO("AUDPLAY4TASK", 17, 4, 1),  /* AudPlay4BitStreamCtrlQueue */
};

static struct msm_adspdec_database msm_device_adspdec_database = {
	.num_dec = ARRAY_SIZE(dec_info_list),
	.num_concurrency_support = (ARRAY_SIZE(dec_concurrency_table) / \
					ARRAY_SIZE(dec_info_list)),
	.dec_concurrency_table = dec_concurrency_table,
	.dec_info_list = dec_info_list,
};

struct platform_device msm_device_adspdec = {
	.name = "msm_adspdec",
	.id = -1,
	.dev    = {
		.platform_data = &msm_device_adspdec_database
	},
};

#define SNDDEV_CAP_NONE 0x0
#define SNDDEV_CAP_RX 0x1 /* RX direction */
#define SNDDEV_CAP_TX 0x2 /* TX direction */
#define SNDDEV_CAP_VOICE 0x4 /* Support voice call */
#define SNDDEV_CAP_FM 0x10 /* Support FM radio */
#define SNDDEV_CAP_TTY 0x20 /* Support TTY */
#define CAD(desc, num, cap) { .name = #desc, .id = num, .capability = cap, }
static struct cad_endpoint cad_endpoints_list[] = {
        CAD(NONE, 0, SNDDEV_CAP_NONE),
        CAD(HANDSET_SPKR, 1, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(HANDSET_MIC, 2, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(HEADSET_MIC, 3, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(HEADSET_SPKR_MONO, 4, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(HEADSET_SPKR_STEREO, 5, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(SPEAKER_PHONE_MIC, 6, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(SPEAKER_PHONE_MONO, 7, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(SPEAKER_PHONE_STEREO, 8, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(BT_SCO_MIC, 9, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(BT_SCO_SPKR, 10, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(BT_A2DP_SPKR, 11, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(TTY_HEADSET_MIC, 12, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE | SNDDEV_CAP_TTY)),
        CAD(TTY_HEADSET_SPKR, 13, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE | SNDDEV_CAP_TTY)),
        CAD(HANDSET_SPKR_HAC, 14,(SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(HANDSET_MIC_ENDFIRE, 15, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(HANDSET_SUBMIC, 16, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(SPEAKER_PHONE_MIC_ENDFIRE, 17, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(SPEAKER_SUBMIC, 18, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(STEREO_SPEAKER_SUBMIC, 19, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(HEADSET_STEREO_PLUS_SPKR_MONO_RX, 20, \
                     (SNDDEV_CAP_RX |SNDDEV_CAP_VOICE)),
        CAD(HEADSET_STEREO_PLUS_SPKR_STEREO_RX, 21, \
                     (SNDDEV_CAP_RX |SNDDEV_CAP_VOICE)),
        CAD(I2S_RX, 22, (SNDDEV_CAP_RX)),
        CAD(I2S_TX, 23, (SNDDEV_CAP_TX)),
        CAD(LP_FM_HEADSET_SPKR_STEREO_RX, 24, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
        CAD(LP_FM_SPEAKER_PHONE_MONO_RX, 25, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
        CAD(LP_FM_SPEAKER_PHONE_STEREO_RX, 26, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
        CAD(LP_FM_HEADSET_SPKR_STEREO_CODEC_RX, 27, \
                    (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
        CAD(FM_RADIO_HEADSET_STEREO, 28, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)), 
        CAD(FM_DIGITAL_HEADSET_SPKR_STEREO, 29, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
        CAD(FM_DIGITAL_SPEAKER_PHONE_MONO, 30, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
        CAD(FM_DIGITAL_BT_A2DP_SPKR, 31, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
        CAD(HEADSET_SPKR_STEREO_MUSIC, 32, (SNDDEV_CAP_RX|SNDDEV_CAP_VOICE)),
        CAD(SPEAKER_PHONE_MONO_MUSIC, 33, (SNDDEV_CAP_RX|SNDDEV_CAP_VOICE)),
        CAD(SPEAKER_PHONE_STEREO_MUSIC, 34,(SNDDEV_CAP_RX|SNDDEV_CAP_VOICE)),
        CAD(MTK_HANDSET_RX, 35, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(MTK_HEADSET_RX, 36, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(MTK_SPEAKER_RX, 37, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        CAD(MTK_HANDSET_MUSIC_TX, 38, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(MTK_HEADSET_MUSIC_TX, 39, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        CAD(MTK_SPEAKER_MUSIC_TX, 40, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
        /* 
          * NOTE: based on SBA 20301C patch, modify the index of audio path. 
          */        
        CAD(SPEAKER_RINGTONE_RX, 41, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),

       CAD(HANDSET_SLOWTALK_RX, 42, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
       CAD(HANDSET_SLOWTALK_TX, 43, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
       CAD(HANDSET_RVE_RX, 44, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
       CAD(HANDSET_RVE_TX, 45, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
       CAD(HANDSET_SLOWTALK_AND_RVE_RX, 46, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
       CAD(HANDSET_SLOWTALK_AND_RVE_TX, 47, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
       CAD(HEADSET_SLOWTALK_RX, 48, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
       CAD(HEADSET_SLOWTALK_TX, 49, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
       CAD(SPEAKER_SLOWTALK_RX, 50, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
       CAD(SPEAKER_SLOWTALK_TX, 51, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
        
        CAD(MAX, 80, SNDDEV_CAP_NONE),      
};
#undef CAD

static struct msm_cad_endpoints msm_device_cad_endpoints = {
	.endpoints = cad_endpoints_list,
	.num = sizeof(cad_endpoints_list) / sizeof(struct cad_endpoint)
};

struct platform_device msm_device_cad = {
	.name = "msm_cad",
	.id = -1,
	.dev    = {
		.platform_data = &msm_device_cad_endpoints
	},
};
