from datetime import datetime

class TimerActions:
    def __init__(self) -> None:
        pass

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def timer_action(self, last_updated_at: str, offset: int):
        if last_updated_at == "":
            return False, datetime.today().strftime("%Y-%m-%d %H:%M:%S.%f")
        today = datetime.today()
        last_updated_at = datetime.strptime(last_updated_at, '%Y-%m-%d %H:%M:%S.%f')
        delta = today - last_updated_at
        delta_in_minutes = delta.total_seconds() / 60
        print(f'[timer]: delta_in_minutes === {delta_in_minutes}', flush=True)
        if delta_in_minutes > offset:
            return True, today.strftime("%Y-%m-%d %H:%M:%S.%f")
        return False, last_updated_at.strftime("%Y-%m-%d %H:%M:%S.%f")