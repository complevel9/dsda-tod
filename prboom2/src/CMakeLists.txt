# PrBoom main executable

set(COMMON_SRC
    am_map.c
    am_map.h
    doomdata.h
    doomdef.c
    doomdef.h
    doomstat.c
    doomstat.h
    doomtype.h
    dsda.c
    dsda.h
    dsda/analysis.c
    dsda/analysis.h
    dsda/args.c
    dsda/args.h
    dsda/brute_force.c
    dsda/brute_force.h
    dsda/build.c
    dsda/build.h
    dsda/compatibility.c
    dsda/compatibility.h
    dsda/configuration.c
    dsda/configuration.h
    dsda/console.c
    dsda/console.h
    dsda/data_organizer.c
    dsda/data_organizer.h
    dsda/death.c
    dsda/death.h
    dsda/deh_hash.c
    dsda/deh_hash.h
    dsda/demo.c
    dsda/demo.h
    dsda/endoom.c
    dsda/endoom.h
    dsda/excmd.c
    dsda/excmd.h
    dsda/exdemo.c
    dsda/exdemo.h
    dsda/exhud.c
    dsda/exhud.h
    dsda/features.c
    dsda/features.h
    dsda/game_controller.c
    dsda/game_controller.h
    dsda/ghost.c
    dsda/ghost.h
    dsda/gl/render_scale.c
    dsda/gl/render_scale.h
    dsda/global.c
    dsda/global.h
    dsda/hud_components.h
    dsda/hud_components/ammo_text.c
    dsda/hud_components/ammo_text.h
    dsda/hud_components/armor_text.c
    dsda/hud_components/armor_text.h
    dsda/hud_components/attempts.c
    dsda/hud_components/attempts.h
    dsda/hud_components/base.c
    dsda/hud_components/base.h
    dsda/hud_components/big_ammo.c
    dsda/hud_components/big_ammo.h
    dsda/hud_components/big_armor.c
    dsda/hud_components/big_armor.h
    dsda/hud_components/big_armor_text.c
    dsda/hud_components/big_armor_text.h
    dsda/hud_components/big_artifact.c
    dsda/hud_components/big_artifact.h
    dsda/hud_components/big_health.c
    dsda/hud_components/big_health.h
    dsda/hud_components/big_health_text.c
    dsda/hud_components/big_health_text.h
    dsda/hud_components/command_display.c
    dsda/hud_components/keyboard_display.c
    dsda/hud_components/command_display.h
    dsda/hud_components/composite_time.c
    dsda/hud_components/composite_time.h
    dsda/hud_components/coordinate_display.c
    dsda/hud_components/coordinate_display.h
    dsda/hud_components/event_split.c
    dsda/hud_components/event_split.h
    dsda/hud_components/fps.c
    dsda/hud_components/fps.h
    dsda/hud_components/health_text.c
    dsda/hud_components/health_text.h
    dsda/hud_components/keys.c
    dsda/hud_components/keys.h
    dsda/hud_components/level_splits.c
    dsda/hud_components/level_splits.h
    dsda/hud_components/line_display.c
    dsda/hud_components/line_display.h
    dsda/hud_components/line_distance_tracker.c
    dsda/hud_components/line_distance_tracker.h
    dsda/hud_components/line_tracker.c
    dsda/hud_components/line_tracker.h
    dsda/hud_components/local_time.c
    dsda/hud_components/local_time.h
    dsda/hud_components/mobj_tracker.c
    dsda/hud_components/mobj_tracker.h
    dsda/hud_components/null.c
    dsda/hud_components/null.h
    dsda/hud_components/player_tracker.c
    dsda/hud_components/player_tracker.h
    dsda/hud_components/ready_ammo_text.c
    dsda/hud_components/ready_ammo_text.h
    dsda/hud_components/render_stats.c
    dsda/hud_components/render_stats.h
    dsda/hud_components/sector_tracker.c
    dsda/hud_components/sector_tracker.h
    dsda/hud_components/speed_text.c
    dsda/hud_components/speed_text.h
    dsda/hud_components/stat_totals.c
    dsda/hud_components/stat_totals.h
    dsda/hud_components/tracker.c
    dsda/hud_components/tracker.h
    dsda/hud_components/weapon_text.c
    dsda/hud_components/weapon_text.h
    dsda/input.c
    dsda/input.h
    dsda/key_frame.c
    dsda/key_frame.h
    dsda/line_special.h
    dsda/map_format.c
    dsda/map_format.h
    dsda/mapinfo.c
    dsda/mapinfo.h
    dsda/mapinfo/hexen.c
    dsda/mapinfo/hexen.h
    dsda/mapinfo/legacy.c
    dsda/mapinfo/legacy.h
    dsda/mapinfo/u.c
    dsda/mapinfo/u.h
    dsda/memory.c
    dsda/memory.h
    dsda/mkdir.c
    dsda/mkdir.h
    dsda/mobjinfo.c
    dsda/mobjinfo.h
    dsda/mouse.c
    dsda/mouse.h
    dsda/msecnode.c
    dsda/msecnode.h
    dsda/music.c
    dsda/music.h
    dsda/options.c
    dsda/options.h
    dsda/palette.c
    dsda/palette.h
    dsda/pause.c
    dsda/pause.h
    dsda/pclass.c
    dsda/pclass.h
    dsda/playback.c
    dsda/playback.h
    dsda/quake.c
    dsda/render_stats.c
    dsda/render_stats.h
    dsda/save.c
    dsda/save.h
    dsda/settings.c
    dsda/settings.h
    dsda/sfx.c
    dsda/sfx.h
    dsda/signal_context.h
    dsda/skip.c
    dsda/skip.h
    dsda/sndinfo.c
    dsda/sndinfo.h
    dsda/spawn_number.c
    dsda/spawn_number.h
    dsda/split_tracker.c
    dsda/split_tracker.h
    dsda/sprite.c
    dsda/sprite.h
    dsda/state.c
    dsda/state.h
    dsda/stretch.c
    dsda/stretch.h
    dsda/text_file.c
    dsda/text_file.h
    dsda/thing_id.c
    dsda/thing_id.h
    dsda/time.c
    dsda/time.h
    dsda/tracker.c
    dsda/tracker.h
    dsda/udmf.cpp
    dsda/udmf.h
    dsda/utility.c
    dsda/utility.h
    dstrings.c
    dstrings.h
    d_deh.c
    d_deh.h
    d_englsh.h
    d_event.h
    d_items.c
    d_items.h
    d_main.c
    d_main.h
    d_net.h
    d_player.h
    d_think.h
    d_ticcmd.h
    e6y.c
    e6y.h
    f_finale.c
    f_finale.h
    f_wipe.c
    f_wipe.h
    g_game.c
    g_game.h
    g_overflow.c
    g_overflow.h
    heretic/d_main.c
    heretic/def.h
    heretic/dstrings.h
    heretic/f_finale.h
    heretic/f_finale.c
    heretic/info.c
    heretic/in_lude.c
    heretic/in_lude.h
    heretic/level_names.c
    heretic/mn_menu.c
    heretic/mn_menu.h
    heretic/p_action.h
    heretic/sb_bar.c
    heretic/sb_bar.h
    heretic/sounds.c
    hexen/a_action.c
    hexen/a_action.h
    hexen/info.c
    hexen/f_finale.c
    hexen/f_finale.h
    hexen/h2_main.c
    hexen/in_lude.c
    hexen/in_lude.h
    hexen/p_acs.c
    hexen/p_acs.h
    hexen/p_anim.c
    hexen/p_anim.h
    hexen/p_things.c
    hexen/p_things.h
    hexen/po_man.c
    hexen/po_man.h
    hexen/sn_sonix.c
    hexen/sn_sonix.h
    hexen/sounds.c
    hexen/sv_save.c
    hexen/sv_save.h
    hu_lib.c
    hu_lib.h
    hu_stuff.c
    hu_stuff.h
    info.c
    info.h
    i_capture.c
    i_capture.h
    i_glob.c
    i_glob.h
    i_main.h
    i_pcsound.c
    i_pcsound.h
    i_sound.h
    i_system.h
    i_video.h
    lprintf.c
    lprintf.h
    md5.c
    md5.h
    m_argv.c
    m_argv.h
    m_bbox.c
    m_bbox.h
    m_cheat.c
    m_cheat.h
    m_fixed.h
    m_menu.c
    m_menu.h
    m_misc.c
    m_misc.h
    m_random.c
    m_random.h
    m_swap.h
    p_ceilng.c
    p_doors.c
    p_enemy.c
    p_enemy.h
    p_floor.c
    p_genlin.c
    p_inter.c
    p_inter.h
    p_lights.c
    p_map.c
    p_map.h
    p_maputl.c
    p_maputl.h
    p_mobj.c
    p_mobj.h
    p_plats.c
    p_pspr.c
    p_pspr.h
    p_saveg.c
    p_saveg.h
    p_setup.c
    p_setup.h
    p_sight.c
    p_spec.c
    p_spec.h
    p_switch.c
    p_telept.c
    p_tick.c
    p_tick.h
    p_user.c
    p_user.h
    r_bsp.c
    r_bsp.h
    r_data.c
    r_data.h
    r_defs.h
    r_draw.c
    r_draw.h
    r_filter.c
    r_filter.h
    r_fps.c
    r_fps.h
    r_main.c
    r_main.h
    r_patch.c
    r_patch.h
    r_plane.c
    r_plane.h
    r_segs.c
    r_segs.h
    r_sky.c
    r_sky.h
    r_state.h
    r_things.c
    r_things.h
    scanner.cpp
    scanner.h
    sc_man.c
    sc_man.h
    smooth.c
    smooth.h
    sounds.c
    sounds.h
    st_lib.c
    st_lib.h
    st_stuff.c
    st_stuff.h
    s_advsound.c
    s_advsound.h
    s_sound.c
    s_sound.h
    tables.c
    tables.h
    umapinfo.cpp
    umapinfo.h
    v_video.c
    v_video.h
    wadtbl.c
    wadtbl.h
    wi_stuff.c
    wi_stuff.h
    w_wad.c
    w_wad.h
    z_bmalloc.c
    z_bmalloc.h
    z_zone.c
    z_zone.h
)

set(NET_CLIENT_SRC
    d_client.c
)

if(HAVE_MMAP OR HAVE_CREATE_FILE_MAPPING)
    set(WAD_SRC w_mmap.c)
else()
    set(WAD_SRC w_memcache.c)
endif()

set(MUS2MID_SRC
    memio.c
    memio.h
    mus2mid.c
    mus2mid.h
)

set(SDLDOOM_SOURCES
    SDL/i_main.c
    SDL/i_sound.c
    SDL/i_sshot.c
    SDL/i_system.c
    SDL/i_video.c
)

set(PCSOUND_SOURCES
    PCSOUND/pcsound.c
    PCSOUND/pcsound.h
    PCSOUND/pcsound_linux.c
    PCSOUND/pcsound_sdl.c
    PCSOUND/pcsound_win32.c
)

set(DOOMMUSIC_SOURCES
    MUSIC/dbopl.c
    MUSIC/dbopl.h
    MUSIC/dumbplayer.c
    MUSIC/dumbplayer.h
    MUSIC/flplayer.c
    MUSIC/flplayer.h
    MUSIC/madplayer.c
    MUSIC/madplayer.h
    MUSIC/midifile.c
    MUSIC/midifile.h
    MUSIC/musicplayer.h
    MUSIC/opl.c
    MUSIC/opl.h
    MUSIC/oplplayer.c
    MUSIC/oplplayer.h
    MUSIC/opl_queue.c
    MUSIC/opl_queue.h
    MUSIC/portmidiplayer.c
    MUSIC/portmidiplayer.h
    MUSIC/vorbisplayer.c
    MUSIC/vorbisplayer.h
)

set(EXTRA_FILES
    r_drawcolpipeline.inl
    r_drawcolumn.inl
    r_drawflush.inl
)

set(PRBOOM_PLUS_SOURCES
    ${COMMON_SRC}
    ${NET_CLIENT_SRC}
    ${WAD_SRC}
    ${MUS2MID_SRC}
    ${SDLDOOM_SOURCES}
    ${PCSOUND_SOURCES}
    ${DOOMMUSIC_SOURCES}
    ${EXTRA_FILES}
)

function(AddGameExecutable TARGET SOURCES)
    set(SOURCES
        ${SOURCES}
        gl_clipper.c
        gl_detail.c
        gl_drawinfo.c
        gl_fbo.c
        gl_gamma.c
        gl_hires.c
        gl_intern.h
        gl_light.c
        gl_main.c
        gl_map.c
        gl_missingtexture.c
        gl_opengl.c
        gl_opengl.h
        gl_preprocess.c
        gl_shader.c
        gl_sky.c
        gl_struct.h
        gl_texture.c
        gl_vertex.c
        gl_wipe.c
    )

    if(WIN32)
        add_definitions("-DUSE_WIN32_PCSOUND_DRIVER")
        set(SOURCES
            ${SOURCES}
            ../ICONS/icons.rc
            SDL/SDL_windows_main.c
        )
        if(MSVC)
            set(SOURCES
                ${SOURCES}
                win_opendir.c
                win_opendir.h
            )
        endif()
    endif()

    add_executable(${TARGET} WIN32 ${SOURCES})
    target_include_directories(${TARGET} PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${CMAKE_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    target_link_libraries(${TARGET} PRIVATE
        ${SDL2_LIBRARIES}
    )
    if(WIN32)
        target_link_libraries(${TARGET} PRIVATE
            winmm
            comctl32
        )
    endif()
    set_target_properties(${TARGET} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PRBOOM_OUTPUT_PATH}
    )
    if(SDL2_IMAGE_FOUND)
        target_include_directories(${TARGET} PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS})
        target_link_libraries(${TARGET} PRIVATE ${SDL2_IMAGE_LIBRARIES})
    endif()

    target_include_directories(${TARGET} PRIVATE ${SDL2_MIXER_INCLUDE_DIRS})
    target_link_libraries(${TARGET} PRIVATE ${SDL2_MIXER_LIBRARIES})

    if(ZLIB_FOUND)
        target_include_directories(${TARGET} PRIVATE ${ZLIB_INCLUDE_DIRS})
        target_link_libraries(${TARGET} PRIVATE ${ZLIB_LIBRARIES})
    endif()
    if(LIBMAD_FOUND)
        target_include_directories(${TARGET} PRIVATE ${LIBMAD_INCLUDE_DIRS})
        target_link_libraries(${TARGET} PRIVATE ${LIBMAD_LIBRARIES})
    endif()
    if(FLUIDSYNTH_FOUND)
        target_include_directories(${TARGET} PRIVATE ${FLUIDSYNTH_INCLUDE_DIR})
        target_link_libraries(${TARGET} PRIVATE ${FLUIDSYNTH_LIBRARIES})
    endif()
    if(DUMB_FOUND)
        target_include_directories(${TARGET} PRIVATE ${DUMB_INCLUDE_DIR})
        target_link_libraries(${TARGET} PRIVATE ${DUMB_LIBRARY})
    endif()
    if(VORBIS_FOUND)
        target_include_directories(${TARGET} PRIVATE ${VORBIS_INCLUDE_DIR})
        target_link_libraries(${TARGET} PRIVATE ${VORBISFILE_LIBRARY})
    endif()
    if(PortMidi_FOUND)
        target_include_directories(${TARGET} PRIVATE ${PORTMIDI_INCLUDE_DIR})
        target_link_libraries(${TARGET} PRIVATE ${PORTMIDI_LIBRARIES})
    endif()
    add_dependencies(${TARGET} dsda-doom-wad)

    if(MSVC)
        set_target_properties(${TARGET} PROPERTIES
            LINK_FLAGS "/MANIFEST:NO /SUBSYSTEM:CONSOLE"
        )
        add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND "mt.exe" -manifest \"${CMAKE_CURRENT_SOURCE_DIR}\\..\\ICONS\\dsda-doom.exe.manifest\" -outputresource:\"$<TARGET_FILE:dsda-doom>\"\;\#1
            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${WAD_DATA_PATH} $<TARGET_FILE_DIR:dsda-doom>
        )
    elseif(WIN32)
        set_target_properties(${TARGET} PROPERTIES
            LINK_FLAGS "-mconsole"
        )
    endif()

    install(TARGETS ${TARGET} COMPONENT "Game executable" RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")

    target_link_libraries(${TARGET} PRIVATE
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
    )
endfunction()

AddGameExecutable(dsda-doom "${PRBOOM_PLUS_SOURCES}")
