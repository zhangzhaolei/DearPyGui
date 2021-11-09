import dearpygui.dearpygui as dpg

dpg.create_context()
dpg.configure_app(manual_callback_management=True)
dpg.create_viewport()
dpg.setup_dearpygui()

with dpg.window(label="tutorial", width=500, height=500, show=True):
    dpg.add_button(label="Press me", callback=lambda s, a, u:print("hello world"))

# main loop
dpg.show_viewport()
while dpg.is_dearpygui_running():

    jobs = dpg.get_callback_queue()
    if jobs is None:
        pass
    else:
        for job in jobs:
            if job[0] is None:
                pass
            else:
                job[0](job[1], job[2], job[3])

    dpg.render_dearpygui_frame()  

dpg.destroy_context()